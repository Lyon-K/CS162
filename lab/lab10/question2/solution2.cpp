#include <iostream>

#include "list.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //Type your answer here:
    int count = 0;
    ListNode *current = head, *prev;
    for(;current != NULL; current = current->next){
        count++;
    }
    if(count == n){
        head = head->next;
        return head;
    }
    current = head;
    for(int i = count - n + 1; i > 1; i--){
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    return head;
}
