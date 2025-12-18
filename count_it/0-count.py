#!/usr/bin/python3
"""
Recursive Reddit keyword counter
"""
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    if counts is None:
        counts = {}

        # normalize words and handle duplicates
        for word in word_list:
            key = word.lower()
            counts[key] = counts.get(key, 0)

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "count_it/1.0"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    children = data.get("children", [])

    for post in children:
        title = post["data"]["title"].lower().split()
        for word in counts:
            counts[word] += sum(1 for t in title if t == word)

    after = data.get("after")
    if after:
        return count_words(subreddit, word_list, after, counts)

    # final output
    results = [(k, v) for k, v in counts.items() if v > 0]
    results.sort(key=lambda x: (-x[1], x[0]))

    for word, count in results:
        print(f"{word}: {count}")
