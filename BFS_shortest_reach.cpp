#include <iostream>
#include <vector>  
#include <string>
#include <queue>
#include <sstream>

using namespace std;
/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s)
{
    vector<vector<int>> adjList(n + 1);
    int rib_value = 6;

    for (auto& e : edges)
    {
        int u = e[0];
        int v = e[1];
        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }

    queue<int> q;
    q.push(s);

    vector<int> dist(n + 1, -1);
    dist[s] = 0;

    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop();

        for (int neibh : adjList[curr_node])
        {
            if (dist[neibh] == -1)
            {
                dist[neibh] = dist[curr_node] + rib_value;
                q.push(neibh);
            }
        }

    }

    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (i != s) res.push_back(dist[i]);
    }

    return res;

}

string ltrim(const string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    return (start == string::npos) ? "" : str.substr(start);
}

string rtrim(const string& str)
{
    size_t end = str.find_last_not_of(" \t\n\r");
    return (end == string::npos) ? "" : str.substr(0, end + 1);
}

vector<string> split(const string& str)
{
    vector<string> tokens;
    stringstream ss(str);
    string temp;
    while (ss >> temp) tokens.push_back(temp);
    return tokens;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(); 

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string line;
        getline(cin, line);
        vector<string> first_multiple_input = split(line);

        int n = stoi(first_multiple_input[0]);
        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            getline(cin, line);
            vector<string> parts = split(line);
            edges[i][0] = stoi(parts[0]);
            edges[i][1] = stoi(parts[1]);
        }

        getline(cin, line);
        int s = stoi(ltrim(rtrim(line)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i != result.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
