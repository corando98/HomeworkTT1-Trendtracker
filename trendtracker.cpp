#include <vector>
#include <string>
#include "trendtracker.h"

using namespace std;

Trendtracker::Trendtracker()
{
	// Creates a new Trendtracker tracking no hashtags.
	// 
	// Must run in O(1) time. (linear)
}

void Trendtracker::insert(string ht)
{
	for(int i = 0; i <= E.size(); i++)
            {
                if(E[i].hashtag == ht) break;
                else
                {
                    E.push_back(Entry());
                    E[E.size() - 1].hashtag = ht;
                    E[E.size() - 1].pop = 0;
                    break;
                }
            }
}
int Trendtracker::size()
{
	int size = E.size();
    return size;
}

void Trendtracker::tweeted(string ht)
{
	for(int i = 0; i <= E.size(); i++)
            {
                if(E[i].hashtag == ht)
                {
                    E[i].pop++;
                }
            }
}

int Trendtracker::popularity(string name)
{
	for(int i = 0; i <= E.size(); i++)
            {
                if(E[i].hashtag == name)
                {
                    return E[i].pop;
                }
            
            }
    return -1;
}

string Trendtracker::top_trend()
{
	int mostpop = 0;
            int indexmostpop = 0;
            if(E.size()==0) return "";
            for(int i = 0; i <= E.size(); i++)
            {
                if(E[i].pop > mostpop)
                {
                    mostpop = E[i].pop;
                    indexmostpop = i;
                }
            }
	return E[indexmostpop].hashtag;
}

void Trendtracker::top_three_trends(vector<string> &T)
{
	int top1 = 0,top2 = 0,top3 = 0;
            int itop1=0,itop2=0,itop3=0;
            for(int i = 0; i <= E.size(); i++)
            {
                if(E[i].pop > top1)
                {
                    top1 = E[i].pop;
                    itop1 = i;
                } //Finds most popular
                else if(E[i].pop > top1)
                {
                    top2 = E[i].pop;
                    itop2 = i;
                } //Finds  2 most popular
                else if(E[i].pop > top1)
                {
                    top3 = E[i].pop;
                    itop3 = i;
                } //Finds 3 most popular
            }
            T.push_back(E[itop3].hashtag);
            T.push_back(E[itop2].hashtag);
            T.push_back(E[itop1].hashtag);
}

void Trendtracker::top_k_trends(vector<string> &T, int k)
{
	//WIP
}
