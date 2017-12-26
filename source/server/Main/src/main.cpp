#include <iostream>
#include "FullUrl.h"
using namespace std;

int main()
{
	RiotApi::FullUrl url(RiotApi::RegionalEndpoint::KR);

	cout << url.GetUrlFormat() << endl;

	return 0;
}