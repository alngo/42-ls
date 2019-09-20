watchmedo shell-command \
    --patterns="*.c;*.h" \
    --recursive \
    --command='make re && ./ft_ls' \
    .
