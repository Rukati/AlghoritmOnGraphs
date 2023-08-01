using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel.Design;
using System.Collections;
using System.Data.SqlTypes;

namespace C_
{
    class Program
    {
        static void dfs(int v, ref List<bool> visit, ref List<List<int>> matrix)
        {
            Console.Write(v + " ");
            int u = v - 1;
            visit[u] = true;
            for (int i = 0; i < matrix[u].Count; i++)
            {
                int next_v = matrix[u][i];
                if (!visit[next_v - 1])
                {
                    dfs(next_v, ref visit, ref matrix);
                }
            }
        }

        static void bfs(int v, ref List<bool> visit, ref List<List<int>> matrix, ref Queue<int> q)
        {
            q.Enqueue(v);
            visit[v - 1] = true;
            while (q.Count != 0)
            {
                int u = q.Dequeue() - 1;
                for (int i = 0; i < matrix[u].Count; i++)
                {
                    if (!visit[matrix[u][i] - 1])
                    {
                        q.Enqueue(matrix[u][i]);
                        visit[matrix[u][i] - 1] = true;
                    }

                }
                Console.Write(u + 1 + " ");
            }
        }

        static void Main()
        {
            string file = "C:\\Users\\mega-\\OneDrive\\Рабочий стол\\test (1).csv";
            List<List<int>> matrix = new List<List<int>>();
            using (StreamReader reader = new StreamReader(file))
            {
                int count = 0;
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    string str = "";
                    matrix.Add(new List<int>());
                    for (int i = 0; i < line.Length; i++)
                    {
                        if (line[i] != ',')
                            str += line[i];
                        else
                        {
                            matrix[count].Add(Int32.Parse(str));
                            str = "";
                        }
                    }
                    matrix[count].Add(Int32.Parse(str));
                    count++;
                }
            }

            for (int i = 0; i < matrix.Count; i++)
            {
                for (int j = 0; j < matrix[i].Count; j++)
                {
                    Console.Write(matrix[i][j] + " ");
                }
                Console.WriteLine();
            }

            List<bool> visitedDFS = new List<bool>(new bool[matrix.Count]);
            Console.Write("DFS: ");
            Program.dfs(1, ref visitedDFS, ref matrix);
            Queue<int> q = new Queue<int>();
            Console.Write(" \nBFS: ");
            List<bool> visitedBFS = new List<bool>(new bool[matrix.Count]);
            Program.bfs(1, ref visitedBFS, ref matrix, ref q);

        }
    }
}
