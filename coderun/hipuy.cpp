#include <iostream>
#include <vector>

using namespace std;

void heapifyDown(int idx, vector<int>& heap) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != idx) {
        swap(heap[idx], heap[largest]);
        heapifyDown(largest, heap);
    }
}

void heapifyUp(int idx, vector<int>& heap) {
    int parent = (idx - 1) / 2;

    if (heap[idx] > heap[parent]) {
        swap(heap[idx], heap[parent]);
        heapifyUp(parent, heap);
    }
}

void insert(int x, vector<int>& heap) {
    heap.push_back(x);
    heapifyUp(heap.size() - 1, heap);
}

int extractMax(vector<int>& heap) {
    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0, heap);
    return maxVal;
}

int main (void) {
    int N;
    cin >> N;

    vector<int> heap;

    for (int i = 0; i < N; ++i) {
        int type;
        cin >> type;

        if (type == 0) {
            int x;
            cin >> x;
            insert(x, heap);
        } else {
            cout << extractMax(heap) << endl;
        }
    }

    return 0;
}