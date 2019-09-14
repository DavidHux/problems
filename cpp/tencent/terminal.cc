#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// 完成以下各个类的实现，可以自由的增删函数

struct Dir {
    unordered_map<string, Dir*> dirs;
    set<string> files;
    Dir* parent;
    string name;
    Dir(string n, Dir* p) : name(n) {
        parent = p;
    }
};
struct CC {
    int type;
    string s;
    Dir* d;
    CC(int type, string ss, Dir* dd) : type(type) {
        s = ss;
        d = dd;
    }
};
/**
 * 终端操作上下文环境
 */
class TerminalEnv {
   private:
    // string m_curdir;
   public:
    Dir* curdir;
};

stack<CC> st;

class Command {
   public:
    virtual ~Command() {}
    virtual bool execute(TerminalEnv& env) = 0;
    virtual bool undo(TerminalEnv& env) {
        return true;
    }
};

class AddDirCommand : public Command {
   public:
    static bool execute(TerminalEnv& env, string dirname) {
        if (env.curdir->dirs.count(dirname))
            return false;
        Dir* ne = new Dir(env.curdir->name + dirname + "/", env.curdir);
        env.curdir->dirs[dirname] = ne;
        st.push({1, dirname, NULL});
        return true;
    }
    static bool undo(TerminalEnv& env, string s) {
        if (env.curdir->dirs.count(s) == 0)
            return false;
        delete env.curdir->dirs[s];
        env.curdir->dirs.erase(s);
        return true;
    }
};

class CDCommand : public Command {
   public:
    static bool execute(TerminalEnv& env, string name) {
        if (name == "..") {
            if (env.curdir->parent == NULL)
                return false;
            st.push({2, name, env.curdir});
            env.curdir = env.curdir->parent;
            return true;
        }
        if (env.curdir->dirs.count(name) == 0)
            return false;
        st.push({2, name, env.curdir});
        env.curdir = env.curdir->dirs[name];
        return true;
    }
    static bool undo(TerminalEnv& env, Dir* d) {
        env.curdir = d;
        return true;
    }
};

class AddFileCommand : public Command {
   public:
    static bool execute(TerminalEnv& env, string name) {
        if (env.curdir->files.count(name))
            return false;
        // Dir* ne  = new Dir(dirname, env.curdir);
        env.curdir->files.insert(name);
        st.push({3, name, NULL});
        return true;
    }
    static bool undo(TerminalEnv& env, string s) {
        if (env.curdir->files.count(s) == 0)
            return false;
        env.curdir->files.erase(s);
        return true;
    }
};

int main() {
    int m;
    cin >> m;
    TerminalEnv te;
    string cmd, name;
    // AddDirCommand ad;
    // CDCommand cd;
    // AddFileCommand adf;
    te.curdir = new Dir("/", NULL);
    for (int i = 0; i < m; ++i) {
        // 处理各个命令
        cin >> cmd;
        if (cmd == "undo") {
            if (st.empty()) cout << "None." << endl;
            auto t = st.top();
            // cout<<t.type<<' '<<t.s<<' '<<t.d<<endl;
            st.pop();
            if (t.type == 1) {
                bool ret = AddDirCommand::undo(te, t.s);
                if (ret)
                    cout << "Dir " << t.s << " removed." << endl;
                else {
                    cout << "None." << endl;
                }
            } else if (t.type == 2) {
                bool ret = CDCommand::undo(te, t.d);
                if (ret)
                    cout << te.curdir->name << endl;
                else
                    cout << "None." << endl;
            } else {
                bool ret = AddFileCommand::undo(te, t.s);
                if (ret)
                    cout << "File " << t.s << " removed." << endl;
                else
                    cout << "None." << endl;
            }
        } else if (cmd == "adddir") {
            cin >> name;
            bool ret = AddDirCommand::execute(te, name);
            if (ret)
                cout << te.curdir->name + name + "/" << endl;
            else
                cout << "File exists." << endl;
        } else if (cmd == "addfile") {
            cin >> name;
            bool ret = AddFileCommand::execute(te, name);
            if (ret)
                cout << te.curdir->name + name << endl;
            else
                cout << "File exists." << endl;
        } else {
            cin >> name;
            bool ret = CDCommand::execute(te, name);
            if (ret)
                cout << te.curdir->name << endl;
            else
                cout << "No such dir." << endl;
        }
    }
    return 0;
}