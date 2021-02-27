main()
{
    even(16);
}

void even(int n)
{
    if(n>=2)
    {
        if(n%2==0)
            {
                even(n-2);
                printf("%d  ",n);
            }
        else
            even(n-1);

    }
}
