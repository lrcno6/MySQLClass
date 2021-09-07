## MySQLClass alpha 2.1

a class to use the *MySQL* client in *C++*

### version content

- alpha 1.2: the first pushed version

- alpha 2.1: rewrite the entire library

license: *LGPL-3.0*

*GitHub* address: https://github.com/lrcno6/MySQLClass

---

*MySQLClass* is a class library that allows you to use *MySQL Client* by classes.

It's used to execute the *MySQL* commands. You can also get the result of the *select* commands.

It only runs on *linux(g++)*. Welcome to port *MySQLClass* to *Windows*!

### how to use it

Make first, then remember to install *libmysqlclient-dev*.

Remember to link libmysql_class.a and libmysqlclient.

such as:

```bash
g++ user.cpp -o user -L./MySQLClass -lmysql_class -lmysqlclient
```

---

Welcome to contribute to *MySQLClass*!

By *lrcno6*