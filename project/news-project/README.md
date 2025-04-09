# News Project
Joel, Jonathan, Harald


## building with make

`make` in the clientserver directory builds the library (in
lib/libclientserver.a) and the example programs
myclient and myserver (in the example directory).

For cleaning, use `make clean` and `make distclean`.

## running the examples

To run the examples, open two terminal windows.

In the first one, start the server with `myserver <port>`, e.g.,

```
example/myserver 7777
```

In the other one, start the client with `myclient <server> <port>`, e.g.,

```
example/myclient localhost 7777
```
