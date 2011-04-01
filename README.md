##Dev-Nu 1.1 

This is an exceptionally fast drop-in replacement for the MySQL backend used by [Omeka](http://omeka.org) intended to allow Omeka to perform at web-scale.

### Compiling

You will need to compile the database on your server using gcc.

    gcc main.c -o dev-nu-1.1

### Usage

    $> ./dev-nu-1.1
    $> set 'item' 'Test'
       Set 'item' to 'Test'
    $> get 'item'
       (null)
    $> exit


### Omeka
This program contains a plugin for Omeka to enable the running dev-nu-1.1 daemon to override the default Omeka database drivers. 

Simply drop the plugin in to your plugins directory and it will convert your data in to the new dev-nu-1.1 format. Alternativley, you can run a
manual export of your data as such:

    mysqldump -u <database_user> -p'<password>' -h <host> omeka > /dev/null 2>&1

### How does it work?
In his seminal paper on relational database systems, E.F. Codd laid out 13 rules a relational database system must follow. These rules, outlined nearly 40 years ago, relied on the structures of computers of the day. Dev-nu rewrites these rules, dropping unneeded cruft like data integrity checks, physical data independence, and comprehensive data sublanguage constraints in favor of high-throughput multi-core parallelism. Because we can write data faster, we no longer need to be constrained by these antiquted, onclusions imposed upon us before most of the people using the Omeka were born.

### More information

* [Mongo DB is Web Scale](http://www.xtranormal.com/watch/6995033/mongo-db-is-web-scale)
