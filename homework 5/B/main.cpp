#include <bits/stdc++.h>
using namespace std;

typedef tuple<string, string, string, string> data;

vector<data> a;

int main() {
	int n;
	cin >> n;
	for (string line; n--; ) {
		cin >> line;
		getline(cin, line);
		smatch name_result, date_result, phone_result, email_result;
		regex_search(line, name_result, regex(R"(^ (am|name is) (\w+).)"));
		regex_search(line, date_result, regex(R"([0-9]{4}[\.-][0-9]{1,2}[\.-][0-9]{1,2})"));
		regex_search(line, phone_result, regex("[0-9]{11}"));
		regex_search(line, email_result, regex(R"(([0-9a-zA-Z]+@[0-9a-zA-Z]+(\.[0-9a-zA-Z]+)+))"));
		string date1 = regex_replace(string(date_result[0]), regex("-"), ".");
		string date2 = regex_replace(date1, regex(R"(\.([0-9])\.)"), ".0$1.");
		string date = regex_replace(date2, regex(R"(\.([0-9])$)"), ".0$1");
		a.push_back({name_result[2], date, phone_result[0], email_result[1]});
	}
	sort(a.begin(), a.end(), [](const data &i, const data &j){return (get<1>(i) < get<1>(j));});
	for (data x: a) {
		cout << get<0>(x) << '-' << get<1>(x) << '-' << get<2>(x) << '-' << get<3>(x) << endl;
	}
	return 0;
}
