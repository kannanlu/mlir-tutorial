#include "mlir/IR/AsmState.h"           // Function for assembly printig and parsing
#include "mlir/IR/BuiltinOps.h"         //ModuleOp
#include "mlir/IR/MLIRContext.h"        // Central data structure
#include "mlir/Parser/Parser.h"         // parseSourceFile, parser for MLIR text
#include "mlir/Support/FileUtilities.h" // MLIR file IO

#include "mlir/Dialect/Func/IR/FuncOps.h" // Function dialect
#include "mlir/Dialect/Arith/IR/Arith.h"  // Arithemetic dialect
#include "llvm/Support/raw_ostream.h"     // LLVM's output stream

using namespace mlir;

int main(int argc, char **argv)
{
  MLIRContext ctx;
  // 首先，注册需要的 dialect
  ctx.loadDialect<func::FuncDialect, arith::ArithDialect>();
  // 读入dialect
  auto src = parseSourceFile<ModuleOp>(argv[1], &ctx);
  // 输出dialect
  src->print(llvm::outs());
  // 简单的输出，在 debug 的时候常用
  src->dump();
  return 0;
}