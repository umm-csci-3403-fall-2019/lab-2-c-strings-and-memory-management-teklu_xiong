#include <gtest/gtest.h>

#include "disemvowel.h"

char *a;

TEST(Disemvowel, HandleEmptyString) {
  a = disemvowel((char*) "");
  ASSERT_STREQ("", a);
  free(a);
}

TEST(Disemvowel, HandleNoVowels) {
  a = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", a);
  free(a);
}

TEST(Disemvowel, HandleOnlyVowels) {
  a = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", a);
  free(a);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  a = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst",
		      a);
  free(a);
}

TEST(Disemvowel, HandlePunctuation) {
  a = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", 
		      a);
  free(a);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;
  char *b;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  b = disemvowel(str);
  ASSERT_STREQ("xyz", b);
  free(b);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
