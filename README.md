A small data exchange program using UNIX signals.

The program will have two executable files, one named 'client' and the other one 'server'

The program will be able to communicate between client and server using SIGUSR1 and SIGUSR2

1. Use "make" before usage.

2. Open two terminal windows.

3. Write ./server.

4. Write ./client <PID printed by the server> "Write the string you want the server to receive".

5. IF NEEDED, in client.c, in ft_transfer_message(), change the number used by usleep, increase it if the program is too fast, decrease if it is too slow.
