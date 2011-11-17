#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MatchMaker{
    public:
        vector <string> getBestMatches(vector <string> param0, string param1, int param2);
        int getnumMatches(string m1, string m2);
};

int MatchMaker::getnumMatches(string m1, string m2){
    int result = 0;
    size_t pos1 = 0, pos2=0;
    pos1 = m1.find_first_of(" ", pos1);
    pos2 = m2.find_first_of(" ", pos2);
    if ( (m1[pos1+1] != m2[pos2+3]) || (m1[pos1+3] != m2[pos2 +1]) )
        return result;
    pos1 += 4; pos2 += 4;
    while(pos1 < m1.length()){
        if(m1[pos1+1] == m2[pos2+1])
            result++;
        pos1+=2; pos2+=2;
    }
    return result;
}


vector <string> MatchMaker::getBestMatches(vector <string> members, string currentUser, int sf){
    vector <string>::iterator it;
    string details, pmatch;
    vector <string> result;
    for(it = members.begin(); it<members.end(); it++){
        details = *it;
        pmatch = details.substr(0, details.find_first_of(" "));
        if(currentUser.compare(pmatch) == 0)
            break;
    }   //details contains data corresponding to currentUser

    for(it = members.begin(); it<members.end(); it++){
        pmatch = *it;
        if(pmatch.compare(0, currentUser.length(), currentUser) != 0){ // Do not match with self
            if(getnumMatches(details, pmatch) >= sf){
                result.push_back(pmatch.substr(0, pmatch.find_first_of(" ")));
            }
        }
    }
    return result;
}

int main(){
    MatchMaker mm;
    vector <string> members;
    vector <string> matches;

        members.push_back("BETTY F M A A C C");
        members.push_back("TOM M F A D C A" );
        members.push_back("SUE F M D D D D");
        members.push_back("ELLEN F M A A C A");
        members.push_back("JOE M F A A C A");
        members.push_back("ED M F A D D A");
        members.push_back("SALLY F M C D A B");
        members.push_back("MARGE F M A A C C");

    matches = mm.getBestMatches(members, "JOE", 1);
    for(int i=0; i< matches.size(); i++)
        cout<<matches[i]<<endl;
	return 0;
}





