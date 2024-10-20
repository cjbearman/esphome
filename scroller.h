/*
scroller can be used to format a message for display to a screen
with the ability to scroll as needed

The message to be displayed should be provided in msg
The output buffer, of max size of number of chars desired (+1), as out
The size of the output buffer as size
post and delay should be pointers to two integers which should be 
initially set to zero
out, pos and delay should all be static within the lambda that is 
calling this function

After calling this function, print the out buffer

The scroll will advance on every display update (assuming this is
called in the display update lambda)

Pauses wil be added at start and end of scroll

*/

void scroller(const char *msg, char *out, int size, int *pos, int *delay) {
    
    if (*delay > 0) {
        (*delay)--;
        return;
    }

    int l = strlen(msg);
    int mc = size -1;
    if (l - *pos < mc) {
        *pos =0;
        *delay = 5;
    }

    snprintf(out, size, "%s", &(msg[*pos]));
    (*pos)++;

    if (l - *pos < mc) {
        *delay = 5;
    }

    
}
