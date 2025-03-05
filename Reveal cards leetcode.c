/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void * x1, const void * x2)   
{
  return ( *(int*)x1 - *(int*)x2 );        
}  

void pushBack(int *newDeck, int current, int deckSize){
    int end = newDeck[deckSize - 1];
    for(int i = deckSize - 2; i >= current; --i){
        newDeck[i + 1] = newDeck[i];
    }
    newDeck[current] = end;
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    *returnSize = deckSize;
    int *newDeck = (int*)malloc(sizeof(int) * (*returnSize));
    qsort(deck, deckSize, sizeof(int), compare); 
    newDeck[deckSize - 1] = deck[deckSize - 1];
   
    for(int i = deckSize - 2; i >= 0; --i){
        pushBack(newDeck, i + 1, deckSize);
        newDeck[i] = deck[i];
    }
    return newDeck;
}
