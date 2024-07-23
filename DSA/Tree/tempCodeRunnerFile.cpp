cout << "Enter the right node :";
        int rightData;
        cin >> rightData;
        root->right = buildTree(rightData);