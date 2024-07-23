#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

vector<int> greaterNode(Node *head)
{
    vector<int> v;

    // TIME COMPLEXITY = O(n^2);
    //..............................................................................................................................................
    // if (head->next == NULL)
    // {
    //     v.push_back(0);
    //     return v;
    // }
    // else
    // {
    //     Node *prv = head;

    //     while (prv != NULL)
    //     {
    //         Node *frd = prv;
    //         while (frd != NULL)
    //         {
    //             if (frd->val > prv->val)
    //             {
    //                 v.push_back(frd->val);
    //                 break;
    //             }
    //             else
    //             {
    //                 frd = frd->next;
    //             }
    //         }
    //         if (frd == NULL)
    //             v.push_back(0);
    //         prv = prv->next;
    //     }
    // }
    //...................................   ...............................................................................................

    // First solution
    //.................         TIME COMPLEXITY O[N]
    // stack<int> st;
    // Node *ptr = head;
    // vector<int> nv;

    // while (ptr != NULL)
    // {
    //     nv.push_back(ptr->val);
    //     ptr = ptr->next;
    // }
    // vector<int> ans(nv.size());
    // // if (head->next == NULL)
    // // {
    // //     v.push_back(0);
    // //     return v;
    // // }
    // // else
    // // {

    // int i = nv.size() - 1;
    // while (i >= 0)
    // {
    //     if (st.empty())
    //     {
    //         ans[i] = 0;
    //         st.push(nv[i]);
    //         i--;
    //     }
    //     else
    //     {
    //         if (nv[i] < st.top())
    //         {
    //             ans[i] = st.top();
    //             st.push(nv[i]);
    //             cout << nv[i] << endl;
    //             i--;
    //         }
    //         else
    //         {
    //             st.pop();
    //             cout << "pop successfull" << endl;
    //         }
    //     }
    // }
    // // }

    // return ans;

    // Second Solution
    //.................

    vector<int> ll;
    stack<int> st;
    while (head)
    {
        ll.push_back(head->val);
        head = head->next;
    }

    vector<int> ans(ll.size());
    for (int i = 0; i < ll.size(); i++)
    {
        while (!st.empty() && ll[i] > ll[st.top()])
        {
            int kid = st.top();
            st.pop();
            ans[kid] = ll[i];
            cout << "ll :" << ll[i] << "kid : " << kid << endl;
        }
        st.push(i);
    }

    return ans;
}

int main()
{

    Node *head = new Node(2);
    Node *n2 = new Node(1);
    Node *n3 = new Node(5);
    Node *n4 = new Node(3);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;

    vector<int> v = greaterNode(head);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}