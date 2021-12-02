listi_t *selectitems(listi_t *h, int min, int max) {
    listi_t *out = NULL, *p;
    
    for (p = head; p->next != NULL; p = p->next) {
        if (p->val > min && p->val < max) {
            out = insertup(out, p->val);
        }
    }

    return out;
}