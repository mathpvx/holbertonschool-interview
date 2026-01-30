/* substring.c */
#include "substring.h"

#include <stdlib.h>
#include <string.h>

/**
 * find_word_id - find the id of a word in the uniq list
 * @p: pointer into s (word starts here)
 * @wlen: word length
 * @uniq: array of unique words
 * @uniq_n: number of unique words
 *
 * Return: index in uniq if found, otherwise -1
 */
static int find_word_id(char const *p, int wlen, char const **uniq, int uniq_n)
{
	int i;

	for (i = 0; i < uniq_n; i++)
	{
		if (strncmp(p, uniq[i], (size_t)wlen) == 0)
			return (i);
	}
	return (-1);
}

/**
 * build_unique - build unique word list + required counts
 * @words: input words array
 * @nb_words: number of words
 * @uniq: output allocated array of unique words (pointers)
 * @req: output allocated array of required counts per unique word
 *
 * Return: number of unique words, or -1 on failure
 */
static int build_unique(char const **words, int nb_words,
			char const ***uniq, int **req)
{
	char const **u;
	int *r;
	int i, j, ucnt;

	ucnt = 0;
	u = malloc(sizeof(*u) * (size_t)nb_words);
	if (!u)
		return (-1);

	r = calloc((size_t)nb_words, sizeof(*r));
	if (!r)
	{
		free(u);
		return (-1);
	}

	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < ucnt; j++)
		{
			if (strcmp(words[i], u[j]) == 0)
			{
				r[j]++;
				break;
			}
		}
		if (j == ucnt)
		{
			u[ucnt] = words[i];
			r[ucnt] = 1;
			ucnt++;
		}
	}

	*uniq = u;
	*req = r;
	return (ucnt);
}

/**
 * push_index - append an integer to a growing array
 * @arr: address of array pointer
 * @len: address of current length
 * @cap: address of current capacity
 * @value: value to append
 *
 * Return: 1 on success, 0 on failure
 */
static int push_index(int **arr, int *len, int *cap, int value)
{
	int new_cap, *tmp;

	if (*len >= *cap)
	{
		new_cap = (*cap == 0) ? 8 : (*cap * 2);
		tmp = realloc(*arr, sizeof(**arr) * (size_t)new_cap);
		if (!tmp)
			return (0);
		*arr = tmp;
		*cap = new_cap;
	}
	(*arr)[*len] = value;
	(*len)++;
	return (1);
}

/**
 * scan_offset - scan s using a fixed offset (0..wlen-1)
 * @s: string to scan
 * @slen: length of s
 * @wlen: word length
 * @nb_words: number of words total
 * @uniq: unique words array
 * @req: required counts per unique word
 * @uniq_n: number of unique words
 * @have: working counts array (size uniq_n)
 * @res: results array pointer
 * @res_len: results length
 * @res_cap: results capacity
 * @offset: current offset
 *
 * Return: 1 on success, 0 on allocation failure
 */
static int scan_offset(char const *s, size_t slen, int wlen, int nb_words,
		       char const **uniq, int *req, int uniq_n, int *have,
		       int **res, int *res_len, int *res_cap, int offset)
{
	size_t left, j;
	int count;

	left = (size_t)offset;
	count = 0;
	memset(have, 0, sizeof(*have) * (size_t)uniq_n);

	for (j = (size_t)offset; j + (size_t)wlen <= slen; j += (size_t)wlen)
	{
		int id;

		id = find_word_id(s + j, wlen, uniq, uniq_n);
		if (id < 0)
		{
			memset(have, 0, sizeof(*have) * (size_t)uniq_n);
			count = 0;
			left = j + (size_t)wlen;
			continue;
		}

		have[id]++;
		count++;

		while (have[id] > req[id])
		{
			int lid;

			lid = find_word_id(s + left, wlen, uniq, uniq_n);
			if (lid >= 0)
				have[lid]--;
			left += (size_t)wlen;
			count--;
		}

		if (count == nb_words)
		{
			int lid;

			if (!push_index(res, res_len, res_cap, (int)left))
				return (0);

			lid = find_word_id(s + left, wlen, uniq, uniq_n);
			if (lid >= 0)
				have[lid]--;
			left += (size_t)wlen;
			count--;
		}
	}
	return (1);
}

/**
 * find_substring - find all start indices of concatenations of all words
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of words
 * @n: address where number of results is stored
 *
 * Return: allocated array of indices, or NULL if none (or on failure)
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int wlen, uniq_n, offset, *req, *have, *res, res_len, res_cap;
	size_t slen;
	char const **uniq;

	if (!n)
		return (NULL);
	*n = 0;

	if (!s || !words || nb_words <= 0 || !words[0])
		return (NULL);

	wlen = (int)strlen(words[0]);
	if (wlen <= 0)
		return (NULL);

	slen = strlen(s);
	if (slen < (size_t)(wlen * nb_words))
		return (NULL);

	uniq_n = build_unique(words, nb_words, &uniq, &req);
	if (uniq_n < 0)
		return (NULL);

	have = calloc((size_t)uniq_n, sizeof(*have));
	if (!have)
	{
		free((void *)uniq);
		free(req);
		return (NULL);
	}

	res = NULL;
	res_len = 0;
	res_cap = 0;

	for (offset = 0; offset < wlen; offset++)
	{
		if (!scan_offset(s, slen, wlen, nb_words, uniq, req, uniq_n, have,
				 &res, &res_len, &res_cap, offset))
		{
			free(have);
			free((void *)uniq);
			free(req);
			free(res);
			return (NULL);
		}
	}

	free(have);
	free((void *)uniq);
	free(req);

	if (res_len == 0)
	{
		free(res);
		return (NULL);
	}

	*n = res_len;
	return (res);
}
