#pragma once

#include <functional> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std;

vector<string> words = { "cat","dog","neko","inu","happy","onegai","ohaiyo","Kampai","car","kurama","Luffy","Wan Pisu","Love","life","Dota","Smash","Zelda","Cosito","medidor","sis" };

vector<string> hashtable_insert(vector<string> words,int i,int table_size)
{
	int collisions = 0, hash_val;
	int n = words.size();
	float load_factor;
	hash<string> hashfunc;
	vector<string>hash_table((int)table_size, "");

	while (i<n)
	{
		hash_val = hashfunc(words[i]) % table_size;

		if (hash_table[hash_val] == "")
			hash_table[hash_val] = words[i];
		else
		{
			int k = 1;
			collisions++;
			int squares = 1;
			int newhash = (hash_val + squares) % table_size;
			while (hash_table[newhash] != "")
			{
				collisions++;
				k++;
				squares += 2 * k - 1;
				newhash = (hash_val + squares) % table_size;
			}

			hash_table[newhash] = words[i];
			
		}
		
		i++;
		load_factor = (float)i / (float)table_size;

		if (load_factor >= 0.5)
		{
			return hashtable_insert(words, 0, 2 * table_size);
		}
	}

	return hash_table;
}



