#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string url;

    // Read URL from text file
    ifstream https_name("https_name.txt");
    https_name >> url;
    https_name.close();

    // Make batch file that calls git clone
    ofstream git_clone("git_clone.bat");
    git_clone << "git clone " << url;
    git_clone.close();

    // Make batch file that calls git push
    ofstream git_push("git_push.bat");
    git_push << "git init" << endl;
    git_push << "git add -A" << endl;
    git_push << "git commit -m 'Updated'" << endl;
    git_push << "git remote add origin " << url << endl;
    git_push << "git push -u origin master" << endl;
    git_push.close();

    return 0;
}