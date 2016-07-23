#include <iostream>
#include <map>
using namespace std;
class Candidate {
public:
	Candidate (string const& name = "") :
		m_name (name), m_votes (0) {}
	string const& name (void) const {
		return m_name;
	}
	size_t votes (void) const {
		return m_votes;
	}
	void vote (void) {
		++m_votes;
	}
private:
	string m_name;
	size_t m_votes;
};
int main (void) {
	map<char, Candidate> cs;
	cs.insert (pair<char, Candidate> ('A',
		Candidate ("张飞")));
	cs.insert (make_pair ('B',
		Candidate ("赵云")));
	cs['C'] = Candidate ("关羽");
	cs['D'] = Candidate ("刘备");
	cs['E'] = Candidate ("曹操");
	typedef map<char, Candidate>::iterator IT;
	pair<IT, bool> res = cs.insert (make_pair (
		'C', "杨健"));
	if (! res.second)
		cout << "插入失败！" << endl;
	cs['C'] = Candidate ("杨健");
	for (size_t i = 0; i < 10; ++i) {
		for (IT it = cs.begin ();
			it != cs.end (); ++it)
			cout << '(' << it->first << ") "
				<< it->second.name () << ' ';
		cout << endl << "请投下宝贵的一票："
			<< flush;
		char key;
		cin >> key;
		IT it = cs.find (key);
		if (it == cs.end ()) {
			cout << "废票！" << endl;
			continue;
		}
		it->second.vote ();
	}
	IT win = cs.begin ();
	for (IT it = cs.begin (); it != cs.end ();
		++it) {
		cout << it->second.name () << "获得"
			<< it->second.votes () << "票。"
			<< endl;
		if (it->second.votes () >
			win->second.votes ())
			win = it;
	}
	cout << "热烈祝贺" << win->second.name ()
		<< "同志成功当选为首席保洁员！" << endl;
	return 0;
}
