int countMinReversals(string expr)
{
    int len = expr.length();
    if (len % 2 != 0) {
        return -1;
    }
    int left_brace = 0, right_brace = 0;
    int ans;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '{') {
            left_brace++;
        }
        else {
            if (left_brace == 0) {
                right_brace++;
            }
            else {
                left_brace--;
            }
        }
    }
    ans = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
    return ans;
}
