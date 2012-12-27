#pragma warning(disable:4996)
#pragma once

#include <vector>
using namespace std;


class Hasse 
{
public:
	static int m_bits;
	static int m_terms;
	static int m_bands;
	static vector<unsigned long> *m_pbands;

	static void initialize(int bits)
	{
		m_bits = bits;
		m_terms = pow(2, bits);
		m_bands = bits + 1;                 
		m_pbands = new vector<unsigned long>[m_bands];   // Delete only once at the end of the or on TotalReset();

		// Allocate space for each bands
		for (int i=0; i<m_terms; i++) {
			m_pbands[Helper::number_of_ones(i)].push_back(i);
		}
	}


	static int get(unsigned long *p, int bias)
	{
		int n=0;
		for (int i=0; i<m_bands; i++) {
			random_shuffle(m_pbands[i].begin(), m_pbands[i].end());
			for (int j=0; j<m_pbands[i].size(); j++) 
				*p++ = m_pbands[i][j] + bias;

			n+=m_pbands[i].size();
		}
		return n;
	}

	static void release()
	{
		delete []m_pbands;
	}
};

#ifdef DEFINE_STATICS
	int Hasse::m_bits;
	int Hasse::m_terms;
	int Hasse::m_bands;
	vector<unsigned long> *Hasse::m_pbands;
#endif