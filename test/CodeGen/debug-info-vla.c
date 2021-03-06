// RUN: %clang_cc1 -emit-llvm -g -triple x86_64-apple-darwin %s -o - | FileCheck %s

void testVLAwithSize(int s)
{
// CHECK: dbg.declare
// CHECK: dbg.declare({{.*}}, metadata ![[VAR:.*]], metadata ![[EXPR:.*]])
// CHECK: ![[VAR]] = {{.*}} ; [ DW_TAG_auto_variable ] [vla] [line [[@LINE+2]]]
// CHECK: ![[EXPR]] = {{.*}} ; [ DW_TAG_expression ] [DW_OP_deref]
  int vla[s];
  int i;
  for (i = 0; i < s; i++) {
    vla[i] = i*i;
  }
}
