#include <iostream>
using namespace std;

// Structure to represent a non-zero element in a sparse matrix
struct Mtx_Nd {
    int ro_idx, co_idx, va_l; // Row, column, and value of the element
    Mtx_Nd* n_xt;             // Pointer to the next node

    // Constructor for initializing a new node
    Mtx_Nd(int r_o, int co_l, int v_a) : ro_idx(r_o), co_idx(co_l), va_l(v_a), n_xt(nullptr) {}
};

// Function to insert a new non-zero value in linked list
void ist_nd(Mtx_Nd*& head, int r_o, int c_o, int v_l) {
    if (v_l == 0) return; // Skip zero values

    // Create a new node for non-zero values
    Mtx_Nd* nu_nod = new Mtx_Nd(r_o, c_o, v_l);

    // Insert the node at the end of the list
    if (!head) {
        head = nu_nod;
        return;
    }

    Mtx_Nd* crnt = head;
    while (crnt->n_xt) {
        crnt = crnt->n_xt;
    }
    crnt->n_xt = nu_nod;
}

// Function to display sparse matrix (linked list)
void dis_lils(Mtx_Nd* head) {
    if (!head) {
        cout << "The matrix has no non-zero elements." << endl;
        return;
    }

    Mtx_Nd* crnt = head;
    // Traverse the list and print each non-zero element
    while (crnt) {
        cout << "Element at (" << crnt->ro_idx << ", " << crnt->co_idx
             << ") = " << crnt->va_l << endl;
        crnt = crnt->n_xt;
    }
}

int main() {
    int nm_ros, nm_cls;

    // Input dimensions of the matrix
    cout << "Number of rows in the matrix: ";
    cin >> nm_ros;
    cout << "Number of columns in the matrix: ";
    cin >> nm_cls;

    Mtx_Nd* sp_mtx = nullptr; // Head of the linked list

    // Input matrix values row by row
    cout << "Input matrix values (row by row, 0 for blanks):" << endl;
    for (int ind_x = 0; ind_x < nm_ros; ++ind_x) {
        for (int ind_y = 0; ind_y < nm_cls; ++ind_y) {
            int v_al;
            cin >> v_al;
            ist_nd(sp_mtx, ind_x, ind_y, v_al); // Add non-zero elements
        }
    }

    // Display sparse matrix in linked list format
    cout << "\nSparse Matrix using Linked List:" << endl;
    dis_lils(sp_mtx);

    return 0;
}
