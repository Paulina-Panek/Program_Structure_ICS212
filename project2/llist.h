class llist
{
  private:
    record *    start;
    char        filename[16];
    int         readfile();
    void         writefile();
    record *    reverse(record * );
    void        cleanup();

  public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord (int, char [ ],char [ ]);
    int printRecord (int);
    int deleteRecord(int);
    void reverse();
};
