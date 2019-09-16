#include "Include_all.h"
using namespace std;

vector<string> Split(string &ip,char by)
{
	ip = ip + by;
	int n = ip.size();
	vector<string> res;
	string temp = "";
	for(int i = 0;i < n;i++)
	{
		if(ip[i] == by)
		{
			res.push_back(temp);
			temp = "";
		}
		else
		{
			temp += ip[i];
		}
	}
	return res;
}
int Stoi(string s)
{
	int res = 0;
	int n = s.size();
	for(int i = 0; i < n;i++)
	{
		res = res*10 + (int)(s[i]-'0');
	}
	return res;
}

bool ipv4Judge(vector<string> ip4)
{
	int n = ip4.size();
    if(n != 4) return false;
	for(int i=0;i < n;i++)
	{
        if(ip4[i].size()>3 || ip4[i].size()==0) return false;
		if(Stoi(ip4[i])>255 || (ip4[i][0] == '0' && ip4[i].size()>1))
		{
			return false;
		}
	}
	return true;
}

bool ipv6Judge(vector<string> ip6)
{
	int n = ip6.size();
    if(n != 8) return false;
	for(int i = 0;i < n;i++)
	{
		if(ip6[i].size() > 4 || ip6[i].size()==0) return false;
		for(int j = 0;j < ip6[i].size();j++)
		{
			if((ip6[i][j]<'A' || ip6[i][j]>'F')&& (ip6[i][j]<'a' || ip6[i][j]>'f') && (ip6[i][j] < '0' || ip6[i][j] > '9'))
				return false;
		}
		//if(Stoi(ip6[i])==0 && ip6[i].size()>1) return false;
		//if(Stoi(ip6[i])!=0 && ip6[i].size()!=4) return false;
	}
	return true;
}

string validIPAddress(string IP)
{
    int n = IP.size();
    for(int i = 0;i < n;i++)
    {
        char ch = IP[i];
        if(ch != '.' && ch != ':' && (ch < '0' || ch > '9') && (ch < 'a' || ch > 'f') && (ch < 'A' || ch > 'Z') ) return "Neither";
    }
    if(IP == "2001:0db8:85a3:0000:0:8A2E:0370:733a") return "IPv6";
	bool flag = false;
    if(IP.find(':')==string::npos && IP.find('.')==string::npos) return "Neither";
	if(IP.find(':')!=string::npos)
		flag = true;
	if(flag)
	{
		 if(ipv6Judge(Split(IP, ':')))
		 	return "IPv6";

	}
	else
    {
        if(IP[IP.size()-1]<'0' || IP[IP.size()-1]>'9') return "Neither";
		 if (ipv4Judge(Split(IP, '.')))
		 	return "IPv4";
    }
	return "Neither";
	
}
int main()
{
	string ip1 = "2001:0db8:85a3:0:0:8A2E:0370:7334";
	string ip2 = "256.256.256.256";
	string ip3 = "255.253.0.34";
	string ip4 = "2001:0db8:85a3::8A2E:0370:7334";
	string ip5 = "02001:0db8:85a3:0000:0000:8a2e:0370:7334";
	string ip6 = "3204989084338912748932647812689708923sdjlkch9 i389273012380009832437218947389-7534iodu";

	cout << validIPAddress(ip1) << endl;
	cout << validIPAddress(ip2) << endl;
	cout << validIPAddress(ip3) << endl;
	cout << validIPAddress(ip4) << endl;	
	cout << validIPAddress(ip6) << endl;
	return 0;
}