#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0;
	ListNode *p = l1;
	ListNode *q = l2;
	ListNode *s = NULL;
	ListNode *last = NULL;

	int l = 0;
	int r = 0;
	int sum;

	while (p || q || carry) {
	    if (p) {
		l = p->val;
		p = p->next;
	    } else {
		l = 0;
	    }

	    if (q) {
		r = q->val;
		q = q->next;
	    } else {
		r = 0;
	    }

	    sum = l + r + carry;
	    carry = sum / 10;

	    ListNode *node = new ListNode(sum % 10);
	    if (!s) {
		s = node;
		last = node;
	    } else {
		last->next = node;
		last = last->next;
	    }
	}

	return s;
    }
};

int main()
{
    ListNode a(2);
    ListNode b(4);
    ListNode c(3);
    ListNode d(5);
    ListNode e(6);
    ListNode f(4);

    a.next = &b;
    b.next = &c;

    d.next = &e;
    e.next = &f;

    Solution s;
    ListNode *l = s.addTwoNumbers(&a, &d);

    while (l) {
	cout << l->val << " ";
	l = l->next;
    }
    cout << endl;

    return 0;
}
