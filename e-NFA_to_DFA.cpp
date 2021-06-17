// Program to convert nfa or nfa (with epsilon moves) to dfa

#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,set<int>>>> table;
vector<vector<pair<set<int>,set<int>>>> dfa;
int n_states, n_inputs;

void epsilon_closure(int start, set<int> &vec)
{
    pair<int,set<int>> p = table[start].back();
    set<int> st = p.second;
    for(auto &it:st)
    {
        vec.insert(it);
        epsilon_closure(it,vec);
    }
}

void nfa_closure(set<int> states, int input, set<int> &transitions)
{
    for(auto &it: states)
    {
        pair<int,set<int>> p = table[it][input];
        transitions.insert(p.second.begin(),p.second.end());
    }
}
int main()
{
    cout<<"No. of states ";
    cin>>n_states;
    cout<<"No. of inputs ";
    cin>>n_inputs;
    for(int i=0;i<n_states;i++)
    {
        vector<pair<int,set<int>>> vec;
        cout<<"For state "<<i<<endl;
        for(int j=0;j<n_inputs;j++)
        {
            cout<<"No. of states for "<<char(j+97)<<": ";
            int n;
            cin>>n;
            set<int> st;
            for(int k=0;k<n;k++)
            {
                cout<<"States: ";
                int temp;
                cin>>temp;
                st.insert(temp);
            }
            vec.push_back(make_pair(j,st));
        }
        cout<<"No. of states for epsilon ";
        int n;
        cin>>n;
        set<int> st;
        for(int k=0;k<n;k++)
        {
            cout<<"States: ";
            int temp;
            cin>>temp;
            st.insert(temp);
        }
        vec.push_back(make_pair(-1,st));
        table.push_back(vec);
    }
    cout << "Enter start state ";
    int start_state;
    cin >> start_state;
    int iterator = 0;
    queue<set<int>> q;
    map<set<int>,int> mp;
    set<int> s_cls;
    s_cls.insert(start_state);
    epsilon_closure(start_state,s_cls);
    q.push(s_cls);
    while(!q.empty())
    {
        set<int> cls = q.front();
        q.pop();
        mp[cls] = iterator;
        iterator++;
        vector<pair<set<int>,set<int>>> vec;
        for(int i=0;i<n_inputs;i++)
        {
            set<int> transitions;
            nfa_closure(cls,i,transitions);
            for(auto &it:transitions)
            {
                epsilon_closure(it,transitions);
            }
            if(!(mp.count(transitions)>0))
            {
                q.push(transitions);
            }
            vec.push_back(make_pair(cls,transitions));
        }
        dfa.push_back(vec);
    }
    cout << endl << "    ";
    for (int i = 0; i < n_inputs; i++)
        cout << char (i + 97) << "  ";
    cout << endl;
    for(int i=0;i<dfa.size();i++)
    {
        bool flag = true;
        for(int j=0;j<dfa[i].size();j++)
        {
            pair<set<int>,set<int>> p =dfa[i][j];
            set<int> i_states = p.first;
            set<int> o_states = p.second;
            if(flag)
            {
                cout<<"{";
                for(auto &it:i_states)
                {
                    cout<<it<<" ";
                }
                cout<<"}";
            }
            flag = false;
            cout<<" : {";
            for(auto &it:o_states)
            {
                cout<<it<<" ";
            }
            cout<<"}";
        }
        cout<<endl;
    }
    return 0;
}
