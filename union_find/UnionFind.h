/*
    Weighted Quick Union w/ Path Compression Data Structure
    by PryDt (Pranoy Dutta)
*/
class UnionFind {

public:
    UnionFind(int N)
    {
        id = new int[N];
        size = new int[N];

        for(int i = 0; i < N; i++)
        {
            id[i] = i;
            size[i] = 1;
        }
    }

    virtual ~UnionFind()
    {
        delete[] id;
        delete[] size;
    }

    // can't be called "union" as that is a keyword in C++
    void connect(int a, int b)
    {
        int rootA = root(a);
        int rootB = root(b);
        if(rootA == rootB)
            return;

        if(size[rootA] < size[rootB])
        {
            id[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else
        {
            id[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }

    bool find(int a, int b)
    {
        return root(a) == root(b);
    }

private:
    int* id;
    int* size;

    int root(int i)
    {
        while(i != id[i])
        {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
};
