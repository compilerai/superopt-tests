// The following are testcases for testing compilations of Clang/LLVM which
// follows a different allocation strategy, depending on the shape, of a struct
// passed as parameter

// requires alloca in O0 body
// alloca preserved in asm
struct s_expanded {
  int x;
  int y;
  // void* z;
};

// requires alloca in O0 body
// alloca mapped to param addr in asm because size matches register size
struct s_expanded_mapped {
  int x; // void* x;
};
//

// no alloca in O0 body
// (byval) attr in LLVM IR for the param
struct s_indir_byval {
  char c;
  // int x;
  // void* z;
};

int foo(void*);

int f_expanded(struct s_expanded p1)
{
  return foo(&p1);
}

int f_expanded_mapped(struct s_expanded_mapped p1)
{
  return foo(&p1);
}

int f_indir_byval(struct s_indir_byval p1)
{
  return foo(&p1);
}
