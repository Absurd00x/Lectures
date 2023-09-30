#include <bits/stdc++.h>

using namespace std;

const int W = 2;

string to_w(int num, int w=W) {
  string res = to_string(num);
  if (w > (int)res.size()) {
    res.insert(0, w - (int)res.size(), ' ');
  }
  return res;
}

/* Глоссарий
Вершина - точка
Ребро - линия, соединяющая вершины
Граф - совокупность множества вершин и множества соединяющих их рёбер
Петля - ребро, соединяющее вершину саму с собой
Кратное ребро - ребро, для которого существует другое ребро, соединяющее такую
  же пару вершин
Смежные вершины - вершины, соединённые ребром
Смежные рёбра - рёбра, у которых один конец совпадает (одна и та же вершина)
Степень вершины - количество рёбер, смежных с данной вершиной
Ориентированное ребро - ребро, у которого есть направление
Ориентированный граф - граф, все рёбра которого имеют направление
Путь в графе - последовательность вершин, соединённых рёбрами
Простой путь - путь, который не проходит по одной и той же вершине несколько раз
Цикл - путь, который начинается и заканчивается в одной вершине
Простой цикл - цикл, который не проходит по одной вершине несколько раз, кроме
  первой и последней
Связный граф - граф, у которого между любой парой вершин существует путь
Компонента связности - максимальный по включению подграф данного графа

Дерево (душно) - граф, у которого между любой парой вершин существует ровно один
  простой путь. Дерево обладает следующими свойствами:
1. Имеет n - 1 ребро
2. Связный
3. Не имеет циклов
Если выполняется 2 из них, то 3е тоже выполняется
Дерево (не душно) - связный граф без циклов

Корень дерева - особая, выделенная вершина в дереве
Подвешенное (корневое) дерево - дерево, у которого есть корень
Предок вершины - вершина, смежная данной, которая располагается ближе к корню
Потомок вершины - вершина, смежная данной, котора располагается дальше от корня
Поддерево вершины v - множество всех вершин, которые содержат v на пути к корню
Бинарное дерево - подвешенное дерево, где у каждой вершины не более 2х потомков

Вес ребра (стоимость ребра) - число, присущее ребру
Вес пути - сумма весов его рёбер
Кратчайший путь - путь с минимальным весом
*/

/* Граф
6 8
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
*/
/* Двоичное дерево
7 6
1 2
1 3
2 4
2 5
3 6
6 7
*/

// Способы представления графа:
typedef pair<int, int> pii;
vector<pii> read_edges(int &n, int &m) {
  // 1. Список рёбер O(m).
  // Каждый элемент обозначает ребро. Что одна одна вершина соединена с другой.
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (auto &[f, t] : edges) {
    cin >> f >> t;
    // Обычно номера вершин идут с 1.
    // Нам в программе удобно с нуля
    --f, --t;
  }
  return edges;
}

vector<vector<bool>> get_adjacency_matrix(int n, vector<pii> &edges) {
  // 2. Матрица смежностей O(n^2).
  // mat[i][j] = 1, если между вершинами i и j существует ребро.
  vector<vector<bool>> mat(n, vector<bool>(n, false));
  for (auto &[f, t] : edges) {
    // Граф неориентированный
    mat[f][t] = mat[t][f] = true;
  }
  return mat;
}

vector<vector<int>> get_adjacency_list(int n, vector<pii> &edges) {
  // 3. Список смежностей O(n + m):
  // g[i] = список смежных для вершин для вершины i.
  vector<vector<int>> g(n);
  for (auto &[f, t] : edges) {
    g[f].push_back(t);
    g[t].push_back(f);
  }
  return g;
}

void show_matrix(vector<vector<bool>> &mat) {
  int n = (int)mat.size();
  cout << string(W, ' ');
  for (int i = 0; i < n; ++i) {
    cout << ' ' << to_w(i + 1);
  }
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    cout << to_w(i + 1);
    for (int j = 0; j < n; ++j) {
      cout << ' ' << to_w(mat[i][j]);
    }
    cout << '\n';
  }
  cout << endl;
}

void show_list(vector<vector<int>> &g) {
  int n = (int)g.size();
  for (int i = 0; i < n; ++i) {
    cout << to_w(i + 1) << ':';
    for (int next : g[i]) {
      cout << ' ' << to_w(next + 1);
    }
    cout << '\n';
  }
  cout << endl;
}

vector<int> _dfs_graph(vector<vector<int>> &g, int start) {
  vector<bool> vis(g.size(), false); // Посетили ли вершину
  vector<int> tour; // Порядок, в котором обошли вершины
  function<void(int)> dfs = [&](int cur) {
    tour.push_back(cur);
    vis[cur] = true;
    for (int next : g[cur]) {
      if (!vis[next]) {
        dfs(next);
      }
    }
  };
  // Не забываем вызывать
  dfs(start);
  return tour;
}

vector<int> _dfs_tree(vector<vector<int>> &g, int start) {
  vector<int> tour; // Порядок, в котором обошли вершины
  function<void(int, int)> dfs = [&](int cur, int prev) {
    tour.push_back(cur);
    for (int next : g[cur]) {
      if (next != prev) {
        dfs(next, cur);
      }
    }
  };
  // Не забываем вызывать
  dfs(start, -1);
  return tour;
}

vector<int> _bfs(vector<vector<int>> &g, int start) {
  int n = (int)g.size();
  vector<int> dists(n, -1); // Расстояние от start до вершины i
  queue<int> q;
  q.push(start);
  dists[start] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : g[cur]) {
      if (dists[next] == -1) {
        dists[next] = dists[cur] + 1;
        q.push(next);
      }
    }
  }
  return dists;
}

int main() {
  int n, m;
  vector<pii> edges = read_edges(n, m);
  vector<vector<bool>> mat = get_adjacency_matrix(n, edges);
  vector<vector<int>> g = get_adjacency_list(n, edges);
  show_matrix(mat);
  show_list(g);
  vector<int> tour = _dfs_graph(g, 0);
  cout << "DFS tour:" << '\n';
  for (int i = 0; i < n; ++i) {
    cout << (i ? " " : "") << tour[i] + 1;
  }
  cout << "\n\n";
  cout << "Shortest distances:" << '\n';
  vector<int> dists = _bfs(g, 0);
  for (int i = 0; i < n; ++i) {
    cout << (i ? " " : "") << i + 1;
  }
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    cout << (i ? " " : "") << dists[i];
  }
  cout << '\n';
  return 0;
}

/* Задачи с div. 4 контестов:
https://codeforces.com/group/U86Pj3Hohe/contest/1676/problem/G
https://codeforces.com/group/U86Pj3Hohe/contest/1760/problem/G
*/