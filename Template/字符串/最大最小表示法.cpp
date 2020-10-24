int min_max_express(bool flag) // flag=true的时候为字典序最小，=false的时候为字典序最大
{
    int i = 0, j = 1, k = 0, t;
    while(i < len && j < len && k < len)
    {
        t = str[(i + k) % len] - str[(j + k) % len];
        if(!t) k++;
        else
        {
            if(flag)
            {
                if(t > 0) i = i + k + 1;
                else j = j + k + 1;
            }
            else
            {
                if(t > 0) j = j + k + 1;
                else i = i + k + 1;
            }

            if(j == i) j++;
            k = 0;
        }
    }

    return i < j ? i : j;
}