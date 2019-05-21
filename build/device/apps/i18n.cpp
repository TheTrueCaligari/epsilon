#include "i18n.h"
#include <apps/global_preferences.h>
#include <assert.h>

namespace I18n {

constexpr static char universalDefault[] = {0};
constexpr static char universalA[] = "a";
constexpr static char universalAbsCommandWithArg[] = "abs(x)";
constexpr static char universalAcoshCommandWithArg[] = "acosh(x)";
constexpr static char universalAlmostEqual[] = "≈";
constexpr static char universalAlpha[] = "alpha";
constexpr static char universalArgCommandWithArg[] = "arg(z)";
constexpr static char universalAsinhCommandWithArg[] = "asinh(x)";
constexpr static char universalAtanhCommandWithArg[] = "atanh(x)";
constexpr static char universalB[] = "b";
constexpr static char universalBinomialCommandWithArg[] = "binomial(n,k)";
constexpr static char universalBlankMessage[] = " ";
constexpr static char universalC[] = "c";
constexpr static char universalCapitalAlpha[] = "ALPHA";
constexpr static char universalCeilCommandWithArg[] = "ceil(x)";
constexpr static char universalCmathModule[] = "cmath";
constexpr static char universalCodeApp[] = "Python";
constexpr static char universalCodeAppCapital[] = "PYTHON";
constexpr static char universalConditionAnd[] = "and ";
constexpr static char universalConditionNot[] = "not ";
constexpr static char universalConditionOr[] = "or ";
constexpr static char universalConditionsMenu[] = "Conditions";
constexpr static char universalConfidenceCommandWithArg[] = "confidence(f,n)";
constexpr static char universalConjCommandWithArg[] = "conj(z)";
constexpr static char universalConsolePrompt[] = ">>> ";
constexpr static char universalCoshCommandWithArg[] = "cosh(x)";
constexpr static char universalCubicRegressionFormula[] = " y=a·x^3+b·x^2+c·x+d ";
constexpr static char universalD[] = "d";
constexpr static char universalDash[] = "-";
constexpr static char universalDeterminantCommandWithArg[] = "det(M)";
constexpr static char universalDiffCommand[] = "diff(\x11,x,\x11)";
constexpr static char universalDiffCommandWithArg[] = "diff(f(x),x,a)";
constexpr static char universalDimensionCommandWithArg[] = "dim(M)";
constexpr static char universalDiscreteLegend[] = "P(X=";
constexpr static char universalDiscriminantFormulaDegree2[] = "Δ=b^2-4ac";
constexpr static char universalE[] = "e";
constexpr static char universalEqual[] = "=";
constexpr static char universalEqualityCondition[] = "==";
constexpr static char universalEqualityConditionWithArg[] = "x==y";
constexpr static char universalExponentialRegressionFormula[] = " y=a·exp(b·x) ";
constexpr static char universalFactorCommandWithArg[] = "factor(n)";
constexpr static char universalFccId[] = "FCC ID";
constexpr static char universalFiniteIntegralLegend[] = "≤X≤";
constexpr static char universalFloorCommandWithArg[] = "floor(x)";
constexpr static char universalForInListLoop[] = "for i in \x11:\n  ";
constexpr static char universalForInListLoopWithArg[] = "for i in list:\n  instruction";
constexpr static char universalForInRange1ArgLoop[] = "for i in range(\x11):\n  ";
constexpr static char universalForInRange1ArgLoopWithArg[] = "for i in range(size):\n  instruction";
constexpr static char universalForInRange2ArgsLoop[] = "for i in range(\x11,):\n  ";
constexpr static char universalForInRange2ArgsLoopWithArg[] = "for i in range(start, stop):\n  instruction";
constexpr static char universalForInRange3ArgsLoop[] = "for i in range(\x11,,):\n  ";
constexpr static char universalForInRange3ArgsLoopWithArg[] = "for i in range(start, stop, step):\n  instruction";
constexpr static char universalForLoopMenu[] = "For";
constexpr static char universalFracCommandWithArg[] = "frac(x)";
constexpr static char universalGcdCommandWithArg[] = "gcd(p,q)";
constexpr static char universalIfAndIfElseStatement[] = "if \x11 and :\n  \nelse:\n  ";
constexpr static char universalIfAndIfElseStatementWithArg[] = "if condition1 and condition2:\n  instruction1\nelse:\n  instruction2";
constexpr static char universalIfElifElseStatement[] = "if \x11:\n  \nelif :\n  \nelse:\n  ";
constexpr static char universalIfElifElseStatementWithArg[] = "if condition1:\n  instruction1\nelif condition2:\n  instruction2\nelse:\n  instruction3";
constexpr static char universalIfElseStatement[] = "if \x11:\n  \nelse:\n  ";
constexpr static char universalIfElseStatementWithArg[] = "if condition:\n  instruction1\nelse:\n  instruction2";
constexpr static char universalIfOrIfElseStatement[] = "if \x11 or :\n  \nelse:\n  ";
constexpr static char universalIfOrIfElseStatementWithArg[] = "if condition1 or condition2:\n  instruction1\nelse:\n  instruction2";
constexpr static char universalIfStatementMenu[] = "If";
constexpr static char universalIfThenStatement[] = "if \x11:\n  ";
constexpr static char universalIfThenStatementWithArg[] = "if condition:\n  instruction";
constexpr static char universalImCommandWithArg[] = "im(z)";
constexpr static char universalIndentityCommandWithArg[] = "identity(n)";
constexpr static char universalInferiorCondition[] = "<=";
constexpr static char universalInferiorConditionWithArg[] = "x<=y";
constexpr static char universalInferiorStrictCondition[] = "<";
constexpr static char universalInferiorStrictConditionWithArg[] = "x<y";
constexpr static char universalIntCommand[] = "int(\x11,x,\x11,\x11)";
constexpr static char universalIntCommandWithArg[] = "int(f(x),x,a,b)";
constexpr static char universalInvSortCommandWithArg[] = "sort>(L)";
constexpr static char universalInverseCommandWithArg[] = "inverse(M)";
constexpr static char universalKandinskyModule[] = "kandinsky";
constexpr static char universalLambda[] = "λ";
constexpr static char universalLanguageDE[] = "Deutsch ";
constexpr static char universalLanguageEN[] = "English ";
constexpr static char universalLanguageES[] = "Español ";
constexpr static char universalLanguageFR[] = "Français ";
constexpr static char universalLanguagePT[] = "Portugués ";
constexpr static char universalLcmCommandWithArg[] = "lcm(p,q)";
constexpr static char universalLeftIntegralFirstLegend[] = "P(X≤";
constexpr static char universalLeftIntegralSecondLegend[] = ")=";
constexpr static char universalLinearRegressionFormula[] = " y=a·x+b ";
constexpr static char universalLogCommandWithArg[] = "log(x,a)";
constexpr static char universalLogarithmicRegressionFormula[] = " y=a·ln(x)+b ";
constexpr static char universalLogisticRegressionFormula[] = " y=c/(a+exp(-b·x)) ";
constexpr static char universalMathModule[] = "math";
constexpr static char universalMatrixCommand[] = "[[\x11]]";
constexpr static char universalMatrixCommandWithArg[] = "[[1,2][3,4]]";
constexpr static char universalMaxCommandWithArg[] = "max(L)";
constexpr static char universalMinCommandWithArg[] = "min(L)";
constexpr static char universalMu[] = "μ";
constexpr static char universalN[] = "n";
constexpr static char universalNonEqualityCondition[] = "!=";
constexpr static char universalNonEqualityConditionWithArg[] = "x!=y";
constexpr static char universalP[] = "p";
constexpr static char universalPermuteCommandWithArg[] = "permute(n,r)";
constexpr static char universalPowerRegressionFormula[] = " y=a·x^b ";
constexpr static char universalPrediction95CommandWithArg[] = "prediction95(p,n)";
constexpr static char universalPredictionCommandWithArg[] = "prediction(p,n)";
constexpr static char universalProductCommand[] = "product(\x11,n,\x11,\x11)";
constexpr static char universalProductCommandWithArg[] = "product(f(n),n,nmin,nmax)";
constexpr static char universalPythonCommand1J[] = "1j";
constexpr static char universalPythonCommandAbs[] = "abs(x)";
constexpr static char universalPythonCommandAcos[] = "acos(x)";
constexpr static char universalPythonCommandAcosh[] = "acosh(x)";
constexpr static char universalPythonCommandAmpersand[] = "&";
constexpr static char universalPythonCommandAsin[] = "asin(x)";
constexpr static char universalPythonCommandAsinh[] = "asinh(x)";
constexpr static char universalPythonCommandAtan[] = "atan(x)";
constexpr static char universalPythonCommandAtan2[] = "atan2(y,x)";
constexpr static char universalPythonCommandAtanh[] = "atanh(x)";
constexpr static char universalPythonCommandBin[] = "bin(x)";
constexpr static char universalPythonCommandCeil[] = "ceil(x)";
constexpr static char universalPythonCommandChoice[] = "choice(list)";
constexpr static char universalPythonCommandCmathFunction[] = "cmath.function";
constexpr static char universalPythonCommandCmathFunctionWithoutArg[] = "cmath.\x11";
constexpr static char universalPythonCommandColor[] = "color(r,g,b)";
constexpr static char universalPythonCommandComplex[] = "complex(a,b)";
constexpr static char universalPythonCommandConstantE[] = "e";
constexpr static char universalPythonCommandConstantPi[] = "pi";
constexpr static char universalPythonCommandCopySign[] = "copysign(x,y)";
constexpr static char universalPythonCommandCos[] = "cos(x)";
constexpr static char universalPythonCommandCosComplex[] = "cos(z)";
constexpr static char universalPythonCommandCosh[] = "cosh(x)";
constexpr static char universalPythonCommandDef[] = "def \x11():\n  ";
constexpr static char universalPythonCommandDefWithArg[] = "def function(x):";
constexpr static char universalPythonCommandDegrees[] = "degrees(x)";
constexpr static char universalPythonCommandDivMod[] = "divmod(a,b)";
constexpr static char universalPythonCommandDrawString[] = "draw_string(\"text\",x,y)";
constexpr static char universalPythonCommandErf[] = "erf(x)";
constexpr static char universalPythonCommandErfc[] = "erfc(x)";
constexpr static char universalPythonCommandEval[] = "eval(\"expression\")";
constexpr static char universalPythonCommandExp[] = "exp(x)";
constexpr static char universalPythonCommandExpComplex[] = "exp(z)";
constexpr static char universalPythonCommandExpm1[] = "expm1(x)";
constexpr static char universalPythonCommandFabs[] = "fabs(x)";
constexpr static char universalPythonCommandFillRect[] = "fill_rect(x,y,width,height,color)";
constexpr static char universalPythonCommandFloat[] = "float(x)";
constexpr static char universalPythonCommandFloor[] = "floor(x)";
constexpr static char universalPythonCommandFmod[] = "fmod(a,b)";
constexpr static char universalPythonCommandFrExp[] = "frexp(x)";
constexpr static char universalPythonCommandGamma[] = "gamma(x)";
constexpr static char universalPythonCommandGetPixel[] = "get_pixel(x,y)";
constexpr static char universalPythonCommandGetrandbits[] = "getrandbits(k)";
constexpr static char universalPythonCommandHex[] = "hex(x)";
constexpr static char universalPythonCommandImag[] = "z.imag";
constexpr static char universalPythonCommandImagWithoutArg[] = "\x11.imag";
constexpr static char universalPythonCommandImportCmath[] = "import cmath";
constexpr static char universalPythonCommandImportFromCmath[] = "from cmath import *";
constexpr static char universalPythonCommandImportFromKandinsky[] = "from kandinsky import *";
constexpr static char universalPythonCommandImportFromMath[] = "from math import *";
constexpr static char universalPythonCommandImportFromRandom[] = "from random import *";
constexpr static char universalPythonCommandImportFromTurtle[] = "from turtle import *";
constexpr static char universalPythonCommandImportKandinsky[] = "import kandinsky";
constexpr static char universalPythonCommandImportMath[] = "import math";
constexpr static char universalPythonCommandImportRandom[] = "import random";
constexpr static char universalPythonCommandImportTurtle[] = "import turtle";
constexpr static char universalPythonCommandInput[] = "input(\"text\")";
constexpr static char universalPythonCommandInt[] = "int(x)";
constexpr static char universalPythonCommandIsFinite[] = "isfinite(x)";
constexpr static char universalPythonCommandIsInfinite[] = "isinf(x)";
constexpr static char universalPythonCommandIsNaN[] = "isnan(x)";
constexpr static char universalPythonCommandKandinskyFunction[] = "kandinsky.function";
constexpr static char universalPythonCommandKandinskyFunctionWithoutArg[] = "kandinsky.\x11";
constexpr static char universalPythonCommandLF[] = "\\n";
constexpr static char universalPythonCommandLdexp[] = "ldexp(x,i)";
constexpr static char universalPythonCommandLength[] = "len(object)";
constexpr static char universalPythonCommandLgamma[] = "lgamma(x)";
constexpr static char universalPythonCommandLog[] = "log(x,a)";
constexpr static char universalPythonCommandLog10[] = "log10(x)";
constexpr static char universalPythonCommandLog2[] = "log2(x)";
constexpr static char universalPythonCommandLogComplex[] = "log(z,a)";
constexpr static char universalPythonCommandMathFunction[] = "math.function";
constexpr static char universalPythonCommandMathFunctionWithoutArg[] = "math.\x11";
constexpr static char universalPythonCommandMax[] = "max(list)";
constexpr static char universalPythonCommandMin[] = "min(list)";
constexpr static char universalPythonCommandModf[] = "modf(x)";
constexpr static char universalPythonCommandOct[] = "oct(x)";
constexpr static char universalPythonCommandPercent[] = "%";
constexpr static char universalPythonCommandPhase[] = "phase(z)";
constexpr static char universalPythonCommandPolar[] = "polar(z)";
constexpr static char universalPythonCommandPound[] = "#";
constexpr static char universalPythonCommandPower[] = "pow(x,y)";
constexpr static char universalPythonCommandPrint[] = "print(object)";
constexpr static char universalPythonCommandRadians[] = "radians(x)";
constexpr static char universalPythonCommandRandint[] = "randint(a,b)";
constexpr static char universalPythonCommandRandom[] = "random()";
constexpr static char universalPythonCommandRandomFunction[] = "random.function";
constexpr static char universalPythonCommandRandomFunctionWithoutArg[] = "random.\x11";
constexpr static char universalPythonCommandRandrange[] = "randrange(start, stop)";
constexpr static char universalPythonCommandRangeStartStop[] = "range(start, stop)";
constexpr static char universalPythonCommandRangeStop[] = "range(stop)";
constexpr static char universalPythonCommandReal[] = "z.real";
constexpr static char universalPythonCommandRealWithoutArg[] = "\x11.real";
constexpr static char universalPythonCommandRect[] = "rect(r, arg)";
constexpr static char universalPythonCommandReturn[] = "return ";
constexpr static char universalPythonCommandRound[] = "round(x, n)";
constexpr static char universalPythonCommandSeed[] = "seed(x)";
constexpr static char universalPythonCommandSetPixel[] = "set_pixel(x,y,color)";
constexpr static char universalPythonCommandSin[] = "sin(x)";
constexpr static char universalPythonCommandSinComplex[] = "sin(z)";
constexpr static char universalPythonCommandSingleQuote[] = "'x'";
constexpr static char universalPythonCommandSinh[] = "sinh(x)";
constexpr static char universalPythonCommandSorted[] = "sorted(list)";
constexpr static char universalPythonCommandSqrt[] = "sqrt(x)";
constexpr static char universalPythonCommandSqrtComplex[] = "sqrt(z)";
constexpr static char universalPythonCommandSum[] = "sum(list)";
constexpr static char universalPythonCommandSymbolExp[] = "^";
constexpr static char universalPythonCommandTab[] = "\\t";
constexpr static char universalPythonCommandTan[] = "tan(x)";
constexpr static char universalPythonCommandTanh[] = "tanh(x)";
constexpr static char universalPythonCommandTrunc[] = "trunc(x)";
constexpr static char universalPythonCommandTurtleFunction[] = "turtle.function";
constexpr static char universalPythonCommandTurtleFunctionWithoutArg[] = "turtle.\x11";
constexpr static char universalPythonCommandUniform[] = "uniform(a,b)";
constexpr static char universalPythonCommandVerticalBar[] = "|";
constexpr static char universalPythonTurtleCommandBackward[] = "backward(x)";
constexpr static char universalPythonTurtleCommandBlack[] = "'black'";
constexpr static char universalPythonTurtleCommandBlue[] = "'blue'";
constexpr static char universalPythonTurtleCommandBrown[] = "'brown'";
constexpr static char universalPythonTurtleCommandCircle[] = "circle(r)";
constexpr static char universalPythonTurtleCommandColor[] = "color('c')/color(r,g,b)";
constexpr static char universalPythonTurtleCommandColorWithoutArg[] = "color(\x11)";
constexpr static char universalPythonTurtleCommandForward[] = "forward(x)";
constexpr static char universalPythonTurtleCommandGoto[] = "goto(x,y)";
constexpr static char universalPythonTurtleCommandGreen[] = "'green'";
constexpr static char universalPythonTurtleCommandGrey[] = "'grey'";
constexpr static char universalPythonTurtleCommandHeading[] = "heading()";
constexpr static char universalPythonTurtleCommandHideturtle[] = "hideturtle()";
constexpr static char universalPythonTurtleCommandIsdown[] = "isdown()";
constexpr static char universalPythonTurtleCommandLeft[] = "left(a)";
constexpr static char universalPythonTurtleCommandOrange[] = "'orange'";
constexpr static char universalPythonTurtleCommandPendown[] = "pendown()";
constexpr static char universalPythonTurtleCommandPensize[] = "pensize(x)";
constexpr static char universalPythonTurtleCommandPenup[] = "penup()";
constexpr static char universalPythonTurtleCommandPink[] = "'pink'";
constexpr static char universalPythonTurtleCommandPosition[] = "position()";
constexpr static char universalPythonTurtleCommandPurple[] = "'purple'";
constexpr static char universalPythonTurtleCommandRed[] = "'red'";
constexpr static char universalPythonTurtleCommandReset[] = "reset()";
constexpr static char universalPythonTurtleCommandRight[] = "right(a)";
constexpr static char universalPythonTurtleCommandSetheading[] = "setheading(a)";
constexpr static char universalPythonTurtleCommandSetposition[] = "setposition(x, [y])";
constexpr static char universalPythonTurtleCommandShowturtle[] = "showturtle()";
constexpr static char universalPythonTurtleCommandSpeed[] = "speed(x)";
constexpr static char universalPythonTurtleCommandWhite[] = "'white'";
constexpr static char universalPythonTurtleCommandYellow[] = "'yellow'";
constexpr static char universalQuadraticRegressionFormula[] = " y=a·x^2+b·x+c ";
constexpr static char universalQuarticRegressionFormula[] = " y=a·x^4+b·x^3+c·x^2+d·x+e ";
constexpr static char universalQuoCommandWithArg[] = "quo(p,q)";
constexpr static char universalR[] = "r";
constexpr static char universalRandintCommandWithArg[] = "randint(a,b)";
constexpr static char universalRandomCommandWithArg[] = "random()";
constexpr static char universalRandomModule[] = "random";
constexpr static char universalReCommandWithArg[] = "re(z)";
constexpr static char universalRemCommandWithArg[] = "rem(p,q)";
constexpr static char universalRightIntegralFirstLegend[] = "P(";
constexpr static char universalRightIntegralSecondLegend[] = "≤X)=";
constexpr static char universalRootCommandWithArg[] = "root(x,n)";
constexpr static char universalRoundCommandWithArg[] = "round(x,n)";
constexpr static char universalScriptParameters[] = "...";
constexpr static char universalShift[] = "shift";
constexpr static char universalSigma[] = "σ";
constexpr static char universalSinhCommandWithArg[] = "sinh(x)";
constexpr static char universalSortCommandWithArg[] = "sort<(L)";
constexpr static char universalSumCommand[] = "sum(\x11,n,\x11,\x11)";
constexpr static char universalSumCommandWithArg[] = "sum(f(n),n,nmin,nmax)";
constexpr static char universalSuperiorCondition[] = ">=";
constexpr static char universalSuperiorConditionWithArg[] = "x>=y";
constexpr static char universalSuperiorStrictCondition[] = ">";
constexpr static char universalSuperiorStrictConditionWithArg[] = "x>y";
constexpr static char universalSxy[] = "∑xy";
constexpr static char universalTanhCommandWithArg[] = "tanh(x)";
constexpr static char universalTraceCommandWithArg[] = "trace(M)";
constexpr static char universalTransposeCommandWithArg[] = "transpose(M)";
constexpr static char universalTrigonometricRegressionFormula[] = " y=a·sin(b·x+c)+d ";
constexpr static char universalTurtleModule[] = "turtle";
constexpr static char universalUSBAppCapital[] = "USB";
constexpr static char universalWhileLoop[] = "while \x11:\n  ";
constexpr static char universalWhileLoopMenu[] = "While";
constexpr static char universalWhileLoopWithArg[] = "while condition:\n  instruction";
constexpr static char universalX[] = "x";
constexpr static char universalXMax[] = "Xmax";
constexpr static char universalXMin[] = "Xmin";
constexpr static char universalY[] = "y";
constexpr static char universalYAuto[] = "Y auto";
constexpr static char universalYMax[] = "Ymax";
constexpr static char universalYMin[] = "Ymin";

constexpr static const char * universalMessages[293] = {
  universalDefault,
  universalA,
  universalAbsCommandWithArg,
  universalAcoshCommandWithArg,
  universalAlmostEqual,
  universalAlpha,
  universalArgCommandWithArg,
  universalAsinhCommandWithArg,
  universalAtanhCommandWithArg,
  universalB,
  universalBinomialCommandWithArg,
  universalBlankMessage,
  universalC,
  universalCapitalAlpha,
  universalCeilCommandWithArg,
  universalCmathModule,
  universalCodeApp,
  universalCodeAppCapital,
  universalConditionAnd,
  universalConditionNot,
  universalConditionOr,
  universalConditionsMenu,
  universalConfidenceCommandWithArg,
  universalConjCommandWithArg,
  universalConsolePrompt,
  universalCoshCommandWithArg,
  universalCubicRegressionFormula,
  universalD,
  universalDash,
  universalDeterminantCommandWithArg,
  universalDiffCommand,
  universalDiffCommandWithArg,
  universalDimensionCommandWithArg,
  universalDiscreteLegend,
  universalDiscriminantFormulaDegree2,
  universalE,
  universalEqual,
  universalEqualityCondition,
  universalEqualityConditionWithArg,
  universalExponentialRegressionFormula,
  universalFactorCommandWithArg,
  universalFccId,
  universalFiniteIntegralLegend,
  universalFloorCommandWithArg,
  universalForInListLoop,
  universalForInListLoopWithArg,
  universalForInRange1ArgLoop,
  universalForInRange1ArgLoopWithArg,
  universalForInRange2ArgsLoop,
  universalForInRange2ArgsLoopWithArg,
  universalForInRange3ArgsLoop,
  universalForInRange3ArgsLoopWithArg,
  universalForLoopMenu,
  universalFracCommandWithArg,
  universalGcdCommandWithArg,
  universalIfAndIfElseStatement,
  universalIfAndIfElseStatementWithArg,
  universalIfElifElseStatement,
  universalIfElifElseStatementWithArg,
  universalIfElseStatement,
  universalIfElseStatementWithArg,
  universalIfOrIfElseStatement,
  universalIfOrIfElseStatementWithArg,
  universalIfStatementMenu,
  universalIfThenStatement,
  universalIfThenStatementWithArg,
  universalImCommandWithArg,
  universalIndentityCommandWithArg,
  universalInferiorCondition,
  universalInferiorConditionWithArg,
  universalInferiorStrictCondition,
  universalInferiorStrictConditionWithArg,
  universalIntCommand,
  universalIntCommandWithArg,
  universalInvSortCommandWithArg,
  universalInverseCommandWithArg,
  universalKandinskyModule,
  universalLambda,
  universalLanguageDE,
  universalLanguageEN,
  universalLanguageES,
  universalLanguageFR,
  universalLanguagePT,
  universalLcmCommandWithArg,
  universalLeftIntegralFirstLegend,
  universalLeftIntegralSecondLegend,
  universalLinearRegressionFormula,
  universalLogCommandWithArg,
  universalLogarithmicRegressionFormula,
  universalLogisticRegressionFormula,
  universalMathModule,
  universalMatrixCommand,
  universalMatrixCommandWithArg,
  universalMaxCommandWithArg,
  universalMinCommandWithArg,
  universalMu,
  universalN,
  universalNonEqualityCondition,
  universalNonEqualityConditionWithArg,
  universalP,
  universalPermuteCommandWithArg,
  universalPowerRegressionFormula,
  universalPrediction95CommandWithArg,
  universalPredictionCommandWithArg,
  universalProductCommand,
  universalProductCommandWithArg,
  universalPythonCommand1J,
  universalPythonCommandAbs,
  universalPythonCommandAcos,
  universalPythonCommandAcosh,
  universalPythonCommandAmpersand,
  universalPythonCommandAsin,
  universalPythonCommandAsinh,
  universalPythonCommandAtan,
  universalPythonCommandAtan2,
  universalPythonCommandAtanh,
  universalPythonCommandBin,
  universalPythonCommandCeil,
  universalPythonCommandChoice,
  universalPythonCommandCmathFunction,
  universalPythonCommandCmathFunctionWithoutArg,
  universalPythonCommandColor,
  universalPythonCommandComplex,
  universalPythonCommandConstantE,
  universalPythonCommandConstantPi,
  universalPythonCommandCopySign,
  universalPythonCommandCos,
  universalPythonCommandCosComplex,
  universalPythonCommandCosh,
  universalPythonCommandDef,
  universalPythonCommandDefWithArg,
  universalPythonCommandDegrees,
  universalPythonCommandDivMod,
  universalPythonCommandDrawString,
  universalPythonCommandErf,
  universalPythonCommandErfc,
  universalPythonCommandEval,
  universalPythonCommandExp,
  universalPythonCommandExpComplex,
  universalPythonCommandExpm1,
  universalPythonCommandFabs,
  universalPythonCommandFillRect,
  universalPythonCommandFloat,
  universalPythonCommandFloor,
  universalPythonCommandFmod,
  universalPythonCommandFrExp,
  universalPythonCommandGamma,
  universalPythonCommandGetPixel,
  universalPythonCommandGetrandbits,
  universalPythonCommandHex,
  universalPythonCommandImag,
  universalPythonCommandImagWithoutArg,
  universalPythonCommandImportCmath,
  universalPythonCommandImportFromCmath,
  universalPythonCommandImportFromKandinsky,
  universalPythonCommandImportFromMath,
  universalPythonCommandImportFromRandom,
  universalPythonCommandImportFromTurtle,
  universalPythonCommandImportKandinsky,
  universalPythonCommandImportMath,
  universalPythonCommandImportRandom,
  universalPythonCommandImportTurtle,
  universalPythonCommandInput,
  universalPythonCommandInt,
  universalPythonCommandIsFinite,
  universalPythonCommandIsInfinite,
  universalPythonCommandIsNaN,
  universalPythonCommandKandinskyFunction,
  universalPythonCommandKandinskyFunctionWithoutArg,
  universalPythonCommandLF,
  universalPythonCommandLdexp,
  universalPythonCommandLength,
  universalPythonCommandLgamma,
  universalPythonCommandLog,
  universalPythonCommandLog10,
  universalPythonCommandLog2,
  universalPythonCommandLogComplex,
  universalPythonCommandMathFunction,
  universalPythonCommandMathFunctionWithoutArg,
  universalPythonCommandMax,
  universalPythonCommandMin,
  universalPythonCommandModf,
  universalPythonCommandOct,
  universalPythonCommandPercent,
  universalPythonCommandPhase,
  universalPythonCommandPolar,
  universalPythonCommandPound,
  universalPythonCommandPower,
  universalPythonCommandPrint,
  universalPythonCommandRadians,
  universalPythonCommandRandint,
  universalPythonCommandRandom,
  universalPythonCommandRandomFunction,
  universalPythonCommandRandomFunctionWithoutArg,
  universalPythonCommandRandrange,
  universalPythonCommandRangeStartStop,
  universalPythonCommandRangeStop,
  universalPythonCommandReal,
  universalPythonCommandRealWithoutArg,
  universalPythonCommandRect,
  universalPythonCommandReturn,
  universalPythonCommandRound,
  universalPythonCommandSeed,
  universalPythonCommandSetPixel,
  universalPythonCommandSin,
  universalPythonCommandSinComplex,
  universalPythonCommandSingleQuote,
  universalPythonCommandSinh,
  universalPythonCommandSorted,
  universalPythonCommandSqrt,
  universalPythonCommandSqrtComplex,
  universalPythonCommandSum,
  universalPythonCommandSymbolExp,
  universalPythonCommandTab,
  universalPythonCommandTan,
  universalPythonCommandTanh,
  universalPythonCommandTrunc,
  universalPythonCommandTurtleFunction,
  universalPythonCommandTurtleFunctionWithoutArg,
  universalPythonCommandUniform,
  universalPythonCommandVerticalBar,
  universalPythonTurtleCommandBackward,
  universalPythonTurtleCommandBlack,
  universalPythonTurtleCommandBlue,
  universalPythonTurtleCommandBrown,
  universalPythonTurtleCommandCircle,
  universalPythonTurtleCommandColor,
  universalPythonTurtleCommandColorWithoutArg,
  universalPythonTurtleCommandForward,
  universalPythonTurtleCommandGoto,
  universalPythonTurtleCommandGreen,
  universalPythonTurtleCommandGrey,
  universalPythonTurtleCommandHeading,
  universalPythonTurtleCommandHideturtle,
  universalPythonTurtleCommandIsdown,
  universalPythonTurtleCommandLeft,
  universalPythonTurtleCommandOrange,
  universalPythonTurtleCommandPendown,
  universalPythonTurtleCommandPensize,
  universalPythonTurtleCommandPenup,
  universalPythonTurtleCommandPink,
  universalPythonTurtleCommandPosition,
  universalPythonTurtleCommandPurple,
  universalPythonTurtleCommandRed,
  universalPythonTurtleCommandReset,
  universalPythonTurtleCommandRight,
  universalPythonTurtleCommandSetheading,
  universalPythonTurtleCommandSetposition,
  universalPythonTurtleCommandShowturtle,
  universalPythonTurtleCommandSpeed,
  universalPythonTurtleCommandWhite,
  universalPythonTurtleCommandYellow,
  universalQuadraticRegressionFormula,
  universalQuarticRegressionFormula,
  universalQuoCommandWithArg,
  universalR,
  universalRandintCommandWithArg,
  universalRandomCommandWithArg,
  universalRandomModule,
  universalReCommandWithArg,
  universalRemCommandWithArg,
  universalRightIntegralFirstLegend,
  universalRightIntegralSecondLegend,
  universalRootCommandWithArg,
  universalRoundCommandWithArg,
  universalScriptParameters,
  universalShift,
  universalSigma,
  universalSinhCommandWithArg,
  universalSortCommandWithArg,
  universalSumCommand,
  universalSumCommandWithArg,
  universalSuperiorCondition,
  universalSuperiorConditionWithArg,
  universalSuperiorStrictCondition,
  universalSuperiorStrictConditionWithArg,
  universalSxy,
  universalTanhCommandWithArg,
  universalTraceCommandWithArg,
  universalTransposeCommandWithArg,
  universalTrigonometricRegressionFormula,
  universalTurtleModule,
  universalUSBAppCapital,
  universalWhileLoop,
  universalWhileLoopMenu,
  universalWhileLoopWithArg,
  universalX,
  universalXMax,
  universalXMin,
  universalY,
  universalYAuto,
  universalYMax,
  universalYMin,
};

constexpr static char enAbout[] = "About";
constexpr static char frAbout[] = "A propos";
constexpr static char esAbout[] = "Acerca";
constexpr static char deAbout[] = "Ueber";
constexpr static char ptAbout[] = "Acerca";
constexpr static char enAbsoluteValue[] = "Absolute value";
constexpr static char frAbsoluteValue[] = "Valeur absolue";
constexpr static char esAbsoluteValue[] = "Valor absoluto";
constexpr static char deAbsoluteValue[] = "Betragsfunktion";
constexpr static char ptAbsoluteValue[] = "Valor absoluto";
constexpr static char enActivateDeactivate[] = "Turn on/off";
constexpr static char frActivateDeactivate[] = "Activer/Désactiver";
constexpr static char esActivateDeactivate[] = "Activar/Desactivar";
constexpr static char deActivateDeactivate[] = "Aktivieren/Deaktivieren";
constexpr static char ptActivateDeactivate[] = "Activar/Desactivar";
constexpr static char enActivateExamMode[] = "Activate exam mode";
constexpr static char frActivateExamMode[] = "Activer le mode examen";
constexpr static char esActivateExamMode[] = "Activar el modo examen";
constexpr static char deActivateExamMode[] = "Start Testmodus";
constexpr static char ptActivateExamMode[] = "Inicio modo de exame";
constexpr static char enActiveExamModeMessage1[] = "All your data will be ";
constexpr static char frActiveExamModeMessage1[] = "Toutes vos données seront ";
constexpr static char esActiveExamModeMessage1[] = "Todos sus datos se ";
constexpr static char deActiveExamModeMessage1[] = "Alle Ihre Daten werden ";
constexpr static char ptActiveExamModeMessage1[] = "Todos os seus dados serão ";
constexpr static char enActiveExamModeMessage2[] = "deleted when you activate ";
constexpr static char frActiveExamModeMessage2[] = "supprimées si vous activez ";
constexpr static char esActiveExamModeMessage2[] = "eliminaran al activar ";
constexpr static char deActiveExamModeMessage2[] = "geloescht, wenn Sie den ";
constexpr static char ptActiveExamModeMessage2[] = "apagados se você ligar ";
constexpr static char enActiveExamModeMessage3[] = "the exam mode.";
constexpr static char frActiveExamModeMessage3[] = "le mode examen.";
constexpr static char esActiveExamModeMessage3[] = "el modo examen.";
constexpr static char deActiveExamModeMessage3[] = "Testmodus einschalten.";
constexpr static char ptActiveExamModeMessage3[] = "o modo de exame.";
constexpr static char enAddEquation[] = "Add equation";
constexpr static char frAddEquation[] = "Ajouter une équation";
constexpr static char esAddEquation[] = "Agregar una ecuación";
constexpr static char deAddEquation[] = "Gleichung hinzufuegen";
constexpr static char ptAddEquation[] = "Adicione uma equação";
constexpr static char enAddFunction[] = "Add function";
constexpr static char frAddFunction[] = "Ajouter une fonction";
constexpr static char esAddFunction[] = "Agregar una función";
constexpr static char deAddFunction[] = "Funktion hinzufuegen";
constexpr static char ptAddFunction[] = "Adicionar uma função";
constexpr static char enAddScript[] = "Add a script";
constexpr static char frAddScript[] = "Ajouter un script";
constexpr static char esAddScript[] = "Agregar un archivo";
constexpr static char deAddScript[] = "Skript hinzufuegen";
constexpr static char ptAddScript[] = "Adicionar um script";
constexpr static char enAddSequence[] = "Add sequence";
constexpr static char frAddSequence[] = "Ajouter une suite";
constexpr static char esAddSequence[] = "Agregar una sucesión";
constexpr static char deAddSequence[] = "Folge hinzufuegen";
constexpr static char ptAddSequence[] = "Adicionar uma sequência";
constexpr static char enAgument[] = "Argument";
constexpr static char frAgument[] = "Argument";
constexpr static char esAgument[] = "Argumento";
constexpr static char deAgument[] = "Argument";
constexpr static char ptAgument[] = "Argumento";
constexpr static char enAllowedCharactersAZaz09[] = "Allowed characters: A-Z, a-z, 0-9, _";
constexpr static char frAllowedCharactersAZaz09[] = "Caractères autorisés : A-Z, a-z, 0-9, _";
constexpr static char esAllowedCharactersAZaz09[] = "Caracteres permitidos : A-Z, a-z, 0-9, _";
constexpr static char deAllowedCharactersAZaz09[] = "Erlaubte Zeichen: A-Z, a-z, 0-9, _";
constexpr static char ptAllowedCharactersAZaz09[] = "Caracteres permitidos : A-Z, a-z, 0-9, _";
constexpr static char enAllowedCharactersaz09[] = "Allowed characters: a-z, 0-9, _";
constexpr static char frAllowedCharactersaz09[] = "Caractères autorisés : a-z, 0-9, _";
constexpr static char esAllowedCharactersaz09[] = "Caracteres permitidos : a-z, 0-9, _";
constexpr static char deAllowedCharactersaz09[] = "Erlaubte Zeichen: a-z, 0-9, _";
constexpr static char ptAllowedCharactersaz09[] = "Caracteres permitidos : a-z, 0-9, _";
constexpr static char enAngleUnit[] = "Angle measure";
constexpr static char frAngleUnit[] = "Unité d'angle";
constexpr static char esAngleUnit[] = "Medida del ángulo";
constexpr static char deAngleUnit[] = "Winkeleinheit";
constexpr static char ptAngleUnit[] = "Valor do angulo";
constexpr static char enApproximateSolution[] = "Approximate solution";
constexpr static char frApproximateSolution[] = "Solution approchée";
constexpr static char esApproximateSolution[] = "Solución aproximada";
constexpr static char deApproximateSolution[] = "Ungefaehre Loesung";
constexpr static char ptApproximateSolution[] = "Solução aproximada";
constexpr static char enApproximateSolutionIntervalInstruction0[] = "Enter the interval to search";
constexpr static char frApproximateSolutionIntervalInstruction0[] = "Entrez l'intervalle dans lequel";
constexpr static char esApproximateSolutionIntervalInstruction0[] = "Introduzca el intervalo para";
constexpr static char deApproximateSolutionIntervalInstruction0[] = "Geben Sie das Intervall fuer die Suche";
constexpr static char ptApproximateSolutionIntervalInstruction0[] = "Digite o intervalo para procurar";
constexpr static char enApproximateSolutionIntervalInstruction1[] = "for an approximate solution";
constexpr static char frApproximateSolutionIntervalInstruction1[] = "rechercher une solution approchée";
constexpr static char esApproximateSolutionIntervalInstruction1[] = "buscar una solución aproximada";
constexpr static char deApproximateSolutionIntervalInstruction1[] = "nach einer ungefaehren Loesung ein";
constexpr static char ptApproximateSolutionIntervalInstruction1[] = "uma solução aproximada";
constexpr static char enApps[] = "Applications";
constexpr static char frApps[] = "Applications";
constexpr static char esApps[] = "Aplicaciones";
constexpr static char deApps[] = "Anwendungen";
constexpr static char ptApps[] = "Aplicações";
constexpr static char enAppsCapital[] = "APPLICATIONS";
constexpr static char frAppsCapital[] = "APPLICATIONS";
constexpr static char esAppsCapital[] = "APLICACIONES";
constexpr static char deAppsCapital[] = "ANWENDUNGEN";
constexpr static char ptAppsCapital[] = "APLICACOES";
constexpr static char enArithmetic[] = "Arithmetic";
constexpr static char frArithmetic[] = "Arithmétique";
constexpr static char esArithmetic[] = "Aritmética";
constexpr static char deArithmetic[] = "Arithmetik";
constexpr static char ptArithmetic[] = "Aritmetica";
constexpr static char enAutoImportScript[] = "Auto import in shell";
constexpr static char frAutoImportScript[] = "Importation auto dans la console";
constexpr static char esAutoImportScript[] = "Importación auto en intérprete";
constexpr static char deAutoImportScript[] = "Automatischer Import in Konsole";
constexpr static char ptAutoImportScript[] = "Importação auto no interpretador";
constexpr static char enAxis[] = "Axes";
constexpr static char frAxis[] = "Axes";
constexpr static char esAxis[] = "Ejes";
constexpr static char deAxis[] = "Achsen";
constexpr static char ptAxis[] = "Eixos";
constexpr static char enBarStart[] = "X start";
constexpr static char frBarStart[] = "Début de la série";
constexpr static char esBarStart[] = "Principio de la serie";
constexpr static char deBarStart[] = "Beginn der Serie";
constexpr static char ptBarStart[] = "Início da série";
constexpr static char enBasedLogarithm[] = "Logarithm to base a";
constexpr static char frBasedLogarithm[] = "Logarithme base a";
constexpr static char esBasedLogarithm[] = "Logaritmo en base a";
constexpr static char deBasedLogarithm[] = "Logarithmus zur Basis a";
constexpr static char ptBasedLogarithm[] = "Logaritmo na base a";
constexpr static char enBetaPopUp[] = "Beta pop-up";
constexpr static char frBetaPopUp[] = "Rappel version bêta";
constexpr static char esBetaPopUp[] = "Beta pop-up";
constexpr static char deBetaPopUp[] = "Beta pop-up";
constexpr static char ptBetaPopUp[] = "Beta pop-up";
constexpr static char enBetaVersion[] = "BETA VERSION";
constexpr static char frBetaVersion[] = "VERSION BETA";
constexpr static char esBetaVersion[] = "BETA VERSION";
constexpr static char deBetaVersion[] = "BETA VERSION";
constexpr static char ptBetaVersion[] = "BETA VERSION";
constexpr static char enBetaVersionMessage1[] = "";
constexpr static char frBetaVersionMessage1[] = "Votre appareil dispose d'une version bêta";
constexpr static char esBetaVersionMessage1[] = "";
constexpr static char deBetaVersionMessage1[] = "";
constexpr static char ptBetaVersionMessage1[] = "";
constexpr static char enBetaVersionMessage2[] = "Your device runs a beta software.";
constexpr static char frBetaVersionMessage2[] = "du logiciel. Il est possible que certains";
constexpr static char esBetaVersionMessage2[] = "Your device runs a beta software.";
constexpr static char deBetaVersionMessage2[] = "Your device runs a beta software.";
constexpr static char ptBetaVersionMessage2[] = "Your device runs a beta software.";
constexpr static char enBetaVersionMessage3[] = "You might run into bugs or glitches.";
constexpr static char frBetaVersionMessage3[] = "bugs apparaissent.";
constexpr static char esBetaVersionMessage3[] = "You might run into bugs or glitches.";
constexpr static char deBetaVersionMessage3[] = "You might run into bugs or glitches.";
constexpr static char ptBetaVersionMessage3[] = "You might run into bugs or glitches.";
constexpr static char enBetaVersionMessage4[] = "";
constexpr static char frBetaVersionMessage4[] = "Vous pouvez nous écrire pour nous";
constexpr static char esBetaVersionMessage4[] = "";
constexpr static char deBetaVersionMessage4[] = "";
constexpr static char ptBetaVersionMessage4[] = "";
constexpr static char enBetaVersionMessage5[] = "Please send any feedback to";
constexpr static char frBetaVersionMessage5[] = "faire part de vos retours à";
constexpr static char esBetaVersionMessage5[] = "Please send any feedback to";
constexpr static char deBetaVersionMessage5[] = "Please send any feedback to";
constexpr static char ptBetaVersionMessage5[] = "Please send any feedback to";
constexpr static char enBetaVersionMessage6[] = "contact@numworks.com";
constexpr static char frBetaVersionMessage6[] = "contact@numworks.com";
constexpr static char esBetaVersionMessage6[] = "contact@numworks.com";
constexpr static char deBetaVersionMessage6[] = "contact@numworks.com";
constexpr static char ptBetaVersionMessage6[] = "contact@numworks.com";
constexpr static char enBinomial[] = "Binomial";
constexpr static char frBinomial[] = "Binomiale";
constexpr static char esBinomial[] = "Binomial";
constexpr static char deBinomial[] = "Binomial";
constexpr static char ptBinomial[] = "Binomial";
constexpr static char enBinomialLaw[] = "Binomial distribution";
constexpr static char frBinomialLaw[] = "Loi binomiale";
constexpr static char esBinomialLaw[] = "Distribución binomial";
constexpr static char deBinomialLaw[] = "Binomialverteilung";
constexpr static char ptBinomialLaw[] = "Distribuição binomial";
constexpr static char enBoxTab[] = "Box";
constexpr static char frBoxTab[] = "Boîte";
constexpr static char esBoxTab[] = "Caja";
constexpr static char deBoxTab[] = "Boxplot";
constexpr static char ptBoxTab[] = "Caixa";
constexpr static char enBrightness[] = "Brightness";
constexpr static char frBrightness[] = "Luminosité";
constexpr static char esBrightness[] = "Brillo";
constexpr static char deBrightness[] = "Helligkeit";
constexpr static char ptBrightness[] = "Brilho";
constexpr static char enCalculApp[] = "Calculation";
constexpr static char frCalculApp[] = "Calculs";
constexpr static char esCalculApp[] = "Cálculo";
constexpr static char deCalculApp[] = "Berechnung";
constexpr static char ptCalculApp[] = "Cálculo";
constexpr static char enCalculAppCapital[] = "CALCULATION";
constexpr static char frCalculAppCapital[] = "CALCULS";
constexpr static char esCalculAppCapital[] = "CALCULO";
constexpr static char deCalculAppCapital[] = "BERECHNUNG";
constexpr static char ptCalculAppCapital[] = "CALCULO";
constexpr static char enCalculation[] = "Calculation";
constexpr static char frCalculation[] = "Calculs";
constexpr static char esCalculation[] = "Cálculos";
constexpr static char deCalculation[] = "Berechnung";
constexpr static char ptCalculation[] = "Calculo";
constexpr static char enCancel[] = "Cancel";
constexpr static char frCancel[] = "Annuler";
constexpr static char esCancel[] = "Cancelar";
constexpr static char deCancel[] = "Abbrechen";
constexpr static char ptCancel[] = "Cancelar";
constexpr static char enCartesian[] = "Cartesian ";
constexpr static char frCartesian[] = "Algébrique ";
constexpr static char esCartesian[] = "Binómica ";
constexpr static char deCartesian[] = "Algebraische ";
constexpr static char ptCartesian[] = "Cartesiana ";
constexpr static char enCatalog[] = "Catalog";
constexpr static char frCatalog[] = "Catalogue";
constexpr static char esCatalog[] = "Catalog";
constexpr static char deCatalog[] = "Katalog";
constexpr static char ptCatalog[] = "Catalog";
constexpr static char enCeiling[] = "Ceiling";
constexpr static char frCeiling[] = "Plafond";
constexpr static char esCeiling[] = "Techo";
constexpr static char deCeiling[] = "Obergrenze";
constexpr static char ptCeiling[] = "Teto";
constexpr static char enChooseLaw[] = "Choose the distribution";
constexpr static char frChooseLaw[] = "Choisir le type de loi";
constexpr static char esChooseLaw[] = "Seleccionar la distribución";
constexpr static char deChooseLaw[] = "Waehlen Sie eine Verteilung";
constexpr static char ptChooseLaw[] = "Selecionar a distribuição";
constexpr static char enChooseParameters[] = "Choose parameters";
constexpr static char frChooseParameters[] = "Choisir les paramètres";
constexpr static char esChooseParameters[] = "Seleccionar parámetros";
constexpr static char deChooseParameters[] = "Parameter auswaehlen";
constexpr static char ptChooseParameters[] = "Selecionar os parâmetros";
constexpr static char enChooseSequenceType[] = "Choose sequence type";
constexpr static char frChooseSequenceType[] = "Choisir le type de suite";
constexpr static char esChooseSequenceType[] = "Seleccionar el tipo de sucesión";
constexpr static char deChooseSequenceType[] = "Das Bildungsgesetz der Folge auswaehlen";
constexpr static char ptChooseSequenceType[] = "Escolha o tipo de sequência";
constexpr static char enClearColumn[] = "Clear column";
constexpr static char frClearColumn[] = "Effacer la colonne";
constexpr static char esClearColumn[] = "Borrar la columna";
constexpr static char deClearColumn[] = "Spalte loeschen";
constexpr static char ptClearColumn[] = "Excluir coluna";
constexpr static char enColumnOptions[] = "Column options";
constexpr static char frColumnOptions[] = "Options de la colonne";
constexpr static char esColumnOptions[] = "Opciones de la columna";
constexpr static char deColumnOptions[] = "Optionen der Spalte";
constexpr static char ptColumnOptions[] = "Opções de coluna";
constexpr static char enCombination[] = "Combination";
constexpr static char frCombination[] = "k parmi n";
constexpr static char esCombination[] = "Combinación";
constexpr static char deCombination[] = "Kombination";
constexpr static char ptCombination[] = "Combinacao";
constexpr static char enComplexAbsoluteValue[] = "Absolute value";
constexpr static char frComplexAbsoluteValue[] = "Module";
constexpr static char esComplexAbsoluteValue[] = "Modulo";
constexpr static char deComplexAbsoluteValue[] = "Betrag";
constexpr static char ptComplexAbsoluteValue[] = "Modulo";
constexpr static char enComplexFormat[] = "Complex format";
constexpr static char frComplexFormat[] = "Forme complexe";
constexpr static char esComplexFormat[] = "Forma compleja";
constexpr static char deComplexFormat[] = "Komplex";
constexpr static char ptComplexFormat[] = "Complexos";
constexpr static char enComplexNumber[] = "Complex numbers";
constexpr static char frComplexNumber[] = "Nombres complexes";
constexpr static char esComplexNumber[] = "Números complejos";
constexpr static char deComplexNumber[] = "Komplexe Zahlen";
constexpr static char ptComplexNumber[] = "Numeros complexos";
constexpr static char enCompute[] = "Calculate";
constexpr static char frCompute[] = "Calculer";
constexpr static char esCompute[] = "Calcular";
constexpr static char deCompute[] = "Berechnen";
constexpr static char ptCompute[] = "Calcular";
constexpr static char enComputeProbability[] = "Calculate probabilities";
constexpr static char frComputeProbability[] = "Calculer les probabilités";
constexpr static char esComputeProbability[] = "Calcular las probabilidades";
constexpr static char deComputeProbability[] = "Wahrscheinlichkeit berechnen";
constexpr static char ptComputeProbability[] = "Calcular probabilidades";
constexpr static char enConfidence[] = "Confidence interval";
constexpr static char frConfidence[] = "Intervalle confiance";
constexpr static char esConfidence[] = "Intervalo de confianza";
constexpr static char deConfidence[] = "Konfidenzintervall";
constexpr static char ptConfidence[] = "Intervalo de confianca";
constexpr static char enConjugate[] = "Conjugate";
constexpr static char frConjugate[] = "Conjugué";
constexpr static char esConjugate[] = "Conjugado";
constexpr static char deConjugate[] = "Konjugiert";
constexpr static char ptConjugate[] = "Conjugado";
constexpr static char enConnectedMessage1[] = "To transfer data, browse";
constexpr static char frConnectedMessage1[] = "Pour transférer des données, connectez-";
constexpr static char esConnectedMessage1[] = "Para transferir datos, visite";
constexpr static char deConnectedMessage1[] = "Um Daten zu uebertragen, verbinden";
constexpr static char ptConnectedMessage1[] = "Para transferir dados, navegue";
constexpr static char enConnectedMessage2[] = "our page from your computer";
constexpr static char frConnectedMessage2[] = "vous depuis votre ordinateur sur le site";
constexpr static char esConnectedMessage2[] = "nuestra página desde su ordenador";
constexpr static char deConnectedMessage2[] = "Sie Sich von Ihrem Computer aus mit";
constexpr static char ptConnectedMessage2[] = "na nossa pagina no seu computador";
constexpr static char enConnectedMessage3[] = "workshop.numworks.com";
constexpr static char frConnectedMessage3[] = "workshop.numworks.com";
constexpr static char esConnectedMessage3[] = "workshop.numworks.com";
constexpr static char deConnectedMessage3[] = "workshop.numworks.com.";
constexpr static char ptConnectedMessage3[] = "workshop.numworks.com";
constexpr static char enConnectedMessage4[] = "Press the BACK key of your";
constexpr static char frConnectedMessage4[] = "Appuyez sur la touche RETOUR de la";
constexpr static char esConnectedMessage4[] = "Pulse el botón RETURN de la";
constexpr static char deConnectedMessage4[] = "Druecken Sie die RETURN-Taste am";
constexpr static char ptConnectedMessage4[] = "Pressione o botão RETURN na";
constexpr static char enConnectedMessage5[] = "calculator or unplug it to";
constexpr static char frConnectedMessage5[] = "calculatrice ou débranchez-la pour la";
constexpr static char esConnectedMessage5[] = "calculadora o desenchúfela para";
constexpr static char deConnectedMessage5[] = "Taschenrechner oder ziehen Sie das Kabel,";
constexpr static char ptConnectedMessage5[] = "calculadora ou desligue-la para";
constexpr static char enConnectedMessage6[] = "disconnect it.";
constexpr static char frConnectedMessage6[] = "déconnecter.";
constexpr static char esConnectedMessage6[] = "desconectarla.";
constexpr static char deConnectedMessage6[] = "um die Verbindung zu trennen.";
constexpr static char ptConnectedMessage6[] = "desconectar-la.";
constexpr static char enConsole[] = "Python shell";
constexpr static char frConsole[] = "Console d'exécution";
constexpr static char esConsole[] = "Interprete de comandos";
constexpr static char deConsole[] = "Interaktive Konsole";
constexpr static char ptConsole[] = "Interpretador interativo";
constexpr static char enCopyColumnInList[] = "Export the column to a list";
constexpr static char frCopyColumnInList[] = "Copier la colonne dans une liste";
constexpr static char esCopyColumnInList[] = "Copiar la columna en una lista";
constexpr static char deCopyColumnInList[] = "Die Spalte in einer Liste kopieren";
constexpr static char ptCopyColumnInList[] = "Copie a coluna em uma lista";
constexpr static char enCovariance[] = "Covariance";
constexpr static char frCovariance[] = "Covariance";
constexpr static char esCovariance[] = "Covarianza";
constexpr static char deCovariance[] = "Kovarianz";
constexpr static char ptCovariance[] = "Covariancia";
constexpr static char enCubic[] = "Cubic";
constexpr static char frCubic[] = "Cubique";
constexpr static char esCubic[] = "Cúbica";
constexpr static char deCubic[] = "Kubische";
constexpr static char ptCubic[] = "Cúbica";
constexpr static char enDataNotSuitable[] = "Data not suitable";
constexpr static char frDataNotSuitable[] = "Les données ne conviennent pas";
constexpr static char esDataNotSuitable[] = "Datos no adecuados";
constexpr static char deDataNotSuitable[] = "Daten nicht geeignet";
constexpr static char ptDataNotSuitable[] = "Dados não adequados";
constexpr static char enDataNotSuitableForRegression[] = " Data not suitable for this regression model";
constexpr static char frDataNotSuitableForRegression[] = "Les données ne conviennent pas";
constexpr static char esDataNotSuitableForRegression[] = "Datos no adecuados";
constexpr static char deDataNotSuitableForRegression[] = "Daten sind nicht geeignet";
constexpr static char ptDataNotSuitableForRegression[] = "Dados não adequados";
constexpr static char enDataTab[] = "Data";
constexpr static char frDataTab[] = "Données";
constexpr static char esDataTab[] = "Datos";
constexpr static char deDataTab[] = "Daten";
constexpr static char ptDataTab[] = "Dados";
constexpr static char enDecimal[] = "Decimal ";
constexpr static char frDecimal[] = "Décimal ";
constexpr static char esDecimal[] = "Decimal ";
constexpr static char deDecimal[] = "Dezimal ";
constexpr static char ptDecimal[] = "Decimal ";
constexpr static char enDefaultSetting[] = "Basic settings";
constexpr static char frDefaultSetting[] = "Réglages de base";
constexpr static char esDefaultSetting[] = "Ajustes básicos";
constexpr static char deDefaultSetting[] = "Grundeinstellung";
constexpr static char ptDefaultSetting[] = "Configurações basicas";
constexpr static char enDeg[] = "deg";
constexpr static char frDeg[] = "deg";
constexpr static char esDeg[] = "gra";
constexpr static char deDeg[] = "gra";
constexpr static char ptDeg[] = "gra";
constexpr static char enDegres[] = "Degrees ";
constexpr static char frDegres[] = "Degrés ";
constexpr static char esDegres[] = "Grados ";
constexpr static char deDegres[] = "Grad ";
constexpr static char ptDegres[] = "Graus ";
constexpr static char enDeleteFunction[] = "Delete function";
constexpr static char frDeleteFunction[] = "Supprimer la fonction";
constexpr static char esDeleteFunction[] = "Eliminar la función";
constexpr static char deDeleteFunction[] = "Funktion loeschen";
constexpr static char ptDeleteFunction[] = "Eliminar a função";
constexpr static char enDeleteScript[] = "Delete script";
constexpr static char frDeleteScript[] = "Supprimer le script";
constexpr static char esDeleteScript[] = "Eliminar el archivo";
constexpr static char deDeleteScript[] = "Skript loeschen";
constexpr static char ptDeleteScript[] = "Eliminar o script";
constexpr static char enDeleteSequence[] = "Delete sequence";
constexpr static char frDeleteSequence[] = "Supprimer la suite";
constexpr static char esDeleteSequence[] = "Eliminar la sucesión";
constexpr static char deDeleteSequence[] = "Folge loeschen";
constexpr static char ptDeleteSequence[] = "Eliminar a sequência";
constexpr static char enDerivateNumber[] = "Derivative";
constexpr static char frDerivateNumber[] = "Nombre derivé";
constexpr static char esDerivateNumber[] = "Derivada";
constexpr static char deDerivateNumber[] = "Ableitung";
constexpr static char ptDerivateNumber[] = "Derivada";
constexpr static char enDerivativeFunctionColumn[] = "Derivative function column";
constexpr static char frDerivativeFunctionColumn[] = "Colonne de la fonction derivée";
constexpr static char esDerivativeFunctionColumn[] = "Columna de la derivada";
constexpr static char deDerivativeFunctionColumn[] = "Spalte der Ableitungsfunktion";
constexpr static char ptDerivativeFunctionColumn[] = "Coluna da função derivada";
constexpr static char enDeterminant[] = "Determinant";
constexpr static char frDeterminant[] = "Déterminant";
constexpr static char esDeterminant[] = "Determinante";
constexpr static char deDeterminant[] = "Determinante";
constexpr static char ptDeterminant[] = "Determinante";
constexpr static char enDeviation[] = "Variance";
constexpr static char frDeviation[] = "Variance";
constexpr static char esDeviation[] = "Varianza";
constexpr static char deDeviation[] = "Varianz";
constexpr static char ptDeviation[] = "Variancia";
constexpr static char enDeviationDefinition[] = "σ: Standard deviation";
constexpr static char frDeviationDefinition[] = "σ : Ecart type";
constexpr static char esDeviationDefinition[] = "σ : Desviación típica";
constexpr static char deDeviationDefinition[] = "σ: Standardabweichung";
constexpr static char ptDeviationDefinition[] = "σ : Desvio padrão";
constexpr static char enDimension[] = "Size";
constexpr static char frDimension[] = "Taille";
constexpr static char esDimension[] = "Tamaño";
constexpr static char deDimension[] = "Groesse";
constexpr static char ptDimension[] = "Tamanho";
constexpr static char enDisplayMode[] = "Result format";
constexpr static char frDisplayMode[] = "Format résultat";
constexpr static char esDisplayMode[] = "Formato resultado";
constexpr static char deDisplayMode[] = "Zahlenformat";
constexpr static char ptDisplayMode[] = "Formato numérico";
constexpr static char enDisplayValues[] = "Display values";
constexpr static char frDisplayValues[] = "Afficher les valeurs";
constexpr static char esDisplayValues[] = "Visualizar los valores";
constexpr static char deDisplayValues[] = "Werte anzeigen";
constexpr static char ptDisplayValues[] = "Exibir os valores";
constexpr static char enDoubleRecurrence[] = "Recursive second order";
constexpr static char frDoubleRecurrence[] = "Récurrente d'ordre 2";
constexpr static char esDoubleRecurrence[] = "Recurrencia de orden dos";
constexpr static char deDoubleRecurrence[] = "Rekursion 2. Ordnung";
constexpr static char ptDoubleRecurrence[] = "Recorrência de Segunda Ordem";
constexpr static char enEdition2D[] = "Natural ";
constexpr static char frEdition2D[] = "Naturelle ";
constexpr static char esEdition2D[] = "Natural ";
constexpr static char deEdition2D[] = "Natuerlich ";
constexpr static char ptEdition2D[] = "Natural ";
constexpr static char enEditionLinear[] = "Linear ";
constexpr static char frEditionLinear[] = "En ligne ";
constexpr static char esEditionLinear[] = "En línea ";
constexpr static char deEditionLinear[] = "Linear ";
constexpr static char ptEditionLinear[] = "Em linha ";
constexpr static char enEditionMode[] = "Writing format";
constexpr static char frEditionMode[] = "Format écriture";
constexpr static char esEditionMode[] = "Formato escritura";
constexpr static char deEditionMode[] = "Eingabe";
constexpr static char ptEditionMode[] = "Formato escrita ";
constexpr static char enEmpty[] = "Empty";
constexpr static char frEmpty[] = "Vide";
constexpr static char esEmpty[] = "Vacio";
constexpr static char deEmpty[] = "Leer";
constexpr static char ptEmpty[] = "Vácuo";
constexpr static char enEmptyExpressionBox0[] = "You have not defined any variables.";
constexpr static char frEmptyExpressionBox0[] = "Vous n'avez défini aucune variable.";
constexpr static char esEmptyExpressionBox0[] = "Ninguna variable definida.";
constexpr static char deEmptyExpressionBox0[] = "Sie haben keine Variable definiert.";
constexpr static char ptEmptyExpressionBox0[] = "Nenhuma variável definida.";
constexpr static char enEmptyExpressionBox1[] = "To define a variable, type:";
constexpr static char frEmptyExpressionBox1[] = "Pour définir une variable, tapez :";
constexpr static char esEmptyExpressionBox1[] = "Para definir una, teclear :";
constexpr static char deEmptyExpressionBox1[] = "Um eine Variable zu definieren:";
constexpr static char ptEmptyExpressionBox1[] = "Para definir uma, digite :";
constexpr static char enEmptyExpressionBox2[] = "The variable name can contain:";
constexpr static char frEmptyExpressionBox2[] = "Le nom de la variable peut contenir :";
constexpr static char esEmptyExpressionBox2[] = "El nombre de variable debe contener :";
constexpr static char deEmptyExpressionBox2[] = "Erlaubte Zeichen im Namen:";
constexpr static char ptEmptyExpressionBox2[] = "O nome da variável pode conter:";
constexpr static char enEmptyFunctionBox0[] = "You have not defined any functions.";
constexpr static char frEmptyFunctionBox0[] = "Vous n'avez défini aucune fonction.";
constexpr static char esEmptyFunctionBox0[] = "Ninguna función definida.";
constexpr static char deEmptyFunctionBox0[] = "Sie haben keine Funktion definiert.";
constexpr static char ptEmptyFunctionBox0[] = "Nenhuma função definida.";
constexpr static char enEmptyFunctionBox1[] = "To define a function, type:";
constexpr static char frEmptyFunctionBox1[] = "Pour définir une fonction, tapez :";
constexpr static char esEmptyFunctionBox1[] = "Para definir una, teclear :";
constexpr static char deEmptyFunctionBox1[] = "Um eine Funktion zu definieren:";
constexpr static char ptEmptyFunctionBox1[] = "Para definir uma, digite :";
constexpr static char enEmptyFunctionBox2[] = "The function name can contain:";
constexpr static char frEmptyFunctionBox2[] = "Le nom de la fonction peut contenir :";
constexpr static char esEmptyFunctionBox2[] = "El nombre de función debe contener : ";
constexpr static char deEmptyFunctionBox2[] = "Erlaubte Zeichen im Namen:";
constexpr static char ptEmptyFunctionBox2[] = "O nome da função pode conter:";
constexpr static char enEnableCharacters[] = "A..Z, a..z, 0..9 and _";
constexpr static char frEnableCharacters[] = "A..Z, a..z, 0..9 et _";
constexpr static char esEnableCharacters[] = "A..Z, a..z, 0..9 y _";
constexpr static char deEnableCharacters[] = "A..Z, a..z, 0..9 und _";
constexpr static char ptEnableCharacters[] = "A..Z, a..z, 0..9 y _";
constexpr static char enEnterEquation[] = "Enter an equation";
constexpr static char frEnterEquation[] = "Entrez une équation";
constexpr static char esEnterEquation[] = "Escribe una ecuación";
constexpr static char deEnterEquation[] = "Geben Sie eine Gleichung ein";
constexpr static char ptEnterEquation[] = "Digite uma equação";
constexpr static char enExamMode[] = "Exam mode";
constexpr static char frExamMode[] = "Mode examen";
constexpr static char esExamMode[] = "Modo examen";
constexpr static char deExamMode[] = "Testmodus";
constexpr static char ptExamMode[] = "Modo de Exame";
constexpr static char enExamModeActive[] = "Exam mode: active";
constexpr static char frExamModeActive[] = "Mode examen: actif";
constexpr static char esExamModeActive[] = "Modo examen: activo";
constexpr static char deExamModeActive[] = "Testmodus: aktiv";
constexpr static char ptExamModeActive[] = "Modo de exame : ativo";
constexpr static char enExecuteScript[] = "Execute script";
constexpr static char frExecuteScript[] = "Exécuter le script";
constexpr static char esExecuteScript[] = "Ejecutar el archivo";
constexpr static char deExecuteScript[] = "Skript ausfuehren";
constexpr static char ptExecuteScript[] = "Executar o script";
constexpr static char enExitExamMode1[] = "Exit the exam ";
constexpr static char frExitExamMode1[] = "Voulez-vous sortir ";
constexpr static char esExitExamMode1[] = "Salir del modo ";
constexpr static char deExitExamMode1[] = "Moechten Sie den Testmodus ";
constexpr static char ptExitExamMode1[] = "Você quer sair do modo de ";
constexpr static char enExitExamMode2[] = "mode?";
constexpr static char frExitExamMode2[] = "du mode examen ?";
constexpr static char esExitExamMode2[] = "examen ?";
constexpr static char deExitExamMode2[] = "verlassen?";
constexpr static char ptExitExamMode2[] = "exame ?";
constexpr static char enExplicit[] = "Explicit expression";
constexpr static char frExplicit[] = "Explicite";
constexpr static char esExplicit[] = "Fórmula explícita";
constexpr static char deExplicit[] = "Explizit";
constexpr static char ptExplicit[] = "Explícita";
constexpr static char enExponential[] = "Exponential";
constexpr static char frExponential[] = "Exponentielle";
constexpr static char esExponential[] = "Exponencial";
constexpr static char deExponential[] = "Exponentielle";
constexpr static char ptExponential[] = "Exponencial";
constexpr static char enExponentialLaw[] = "Exponential distribution";
constexpr static char frExponentialLaw[] = "Loi exponentielle";
constexpr static char esExponentialLaw[] = "Distribución exponencial";
constexpr static char deExponentialLaw[] = "Exponentialverteilung";
constexpr static char ptExponentialLaw[] = "Distribuição exponencial";
constexpr static char enExpressions[] = "Expressions";
constexpr static char frExpressions[] = "Expressions";
constexpr static char esExpressions[] = "Expresiones";
constexpr static char deExpressions[] = "Ausdruecke";
constexpr static char ptExpressions[] = "Expressões";
constexpr static char enFillWithFormula[] = "Fill with a formula";
constexpr static char frFillWithFormula[] = "Remplir avec une formule";
constexpr static char esFillWithFormula[] = "Rellenar con una fórmula";
constexpr static char deFillWithFormula[] = "Mit einer Formel fuellen";
constexpr static char ptFillWithFormula[] = "Preencher com uma fórmula";
constexpr static char enFirstQuartile[] = "First quartile";
constexpr static char frFirstQuartile[] = "Premier quartile";
constexpr static char esFirstQuartile[] = "Primer cuartil";
constexpr static char deFirstQuartile[] = "Unteres Quartil";
constexpr static char ptFirstQuartile[] = "Quartil inferior";
constexpr static char enFirstTermIndex[] = "First term index";
constexpr static char frFirstTermIndex[] = "Indice premier terme";
constexpr static char esFirstTermIndex[] = "Indice del primer término";
constexpr static char deFirstTermIndex[] = "Anfangsindex";
constexpr static char ptFirstTermIndex[] = "Indice do primeiro termo";
constexpr static char enFloor[] = "Floor";
constexpr static char frFloor[] = "Partie entière";
constexpr static char esFloor[] = "Parte entera";
constexpr static char deFloor[] = "Untergrenze";
constexpr static char ptFloor[] = "Parte inteira";
constexpr static char enFluctuation[] = "Prediction Interval";
constexpr static char frFluctuation[] = "Intervalle fluctuation";
constexpr static char esFluctuation[] = "Interval de predicción";
constexpr static char deFluctuation[] = "Konfidenzintervall";
constexpr static char ptFluctuation[] = "Intervalo de confianca";
constexpr static char enForbiddenValue[] = "Forbidden value";
constexpr static char frForbiddenValue[] = "Valeur interdite";
constexpr static char esForbiddenValue[] = "Valor prohibido";
constexpr static char deForbiddenValue[] = "Verbotener Wert";
constexpr static char ptForbiddenValue[] = "Valor proibida";
constexpr static char enFracPart[] = "Fractional part";
constexpr static char frFracPart[] = "Partie fractionnaire";
constexpr static char esFracPart[] = "Parte fraccionaria";
constexpr static char deFracPart[] = "Bruchteil";
constexpr static char ptFracPart[] = "Parte fraccionaria";
constexpr static char enFrequency[] = "Frequency";
constexpr static char frFrequency[] = "Fréquence";
constexpr static char esFrequency[] = "Relativa";
constexpr static char deFrequency[] = "Relative";
constexpr static char ptFrequency[] = "Relativa";
constexpr static char enFunctionApp[] = "Functions";
constexpr static char frFunctionApp[] = "Fonctions";
constexpr static char esFunctionApp[] = "Función";
constexpr static char deFunctionApp[] = "Funktionen";
constexpr static char ptFunctionApp[] = "Função";
constexpr static char enFunctionAppCapital[] = "FUNCTIONS";
constexpr static char frFunctionAppCapital[] = "FONCTIONS";
constexpr static char esFunctionAppCapital[] = "FUNCION";
constexpr static char deFunctionAppCapital[] = "FUNKTIONEN";
constexpr static char ptFunctionAppCapital[] = "FUNCAO";
constexpr static char enFunctionColor[] = "Function color";
constexpr static char frFunctionColor[] = "Couleur de la fonction";
constexpr static char esFunctionColor[] = "Color de la funcion";
constexpr static char deFunctionColor[] = "Farbe der Funktion";
constexpr static char ptFunctionColor[] = "Cor da função";
constexpr static char enFunctionColumn[] = "0(0) column";
constexpr static char frFunctionColumn[] = "Colonne 0(0)";
constexpr static char esFunctionColumn[] = "Columna 0(0)";
constexpr static char deFunctionColumn[] = "0(0) Spalte";
constexpr static char ptFunctionColumn[] = "Coluna 0(0)";
constexpr static char enFunctionOptions[] = "Function options";
constexpr static char frFunctionOptions[] = "Options de la fonction";
constexpr static char esFunctionOptions[] = "Opciones de la función";
constexpr static char deFunctionOptions[] = "Funktionsoptionen";
constexpr static char ptFunctionOptions[] = "Opções de função";
constexpr static char enFunctionTab[] = "Functions";
constexpr static char frFunctionTab[] = "Fonctions";
constexpr static char esFunctionTab[] = "Funciones";
constexpr static char deFunctionTab[] = "Funktionen";
constexpr static char ptFunctionTab[] = "Funções";
constexpr static char enFunctions[] = "Functions";
constexpr static char frFunctions[] = "Fonctions";
constexpr static char esFunctions[] = "Funciones";
constexpr static char deFunctions[] = "Funktionen";
constexpr static char ptFunctions[] = "Funçães";
constexpr static char enFunctionsAndVariables[] = "Functions and variables";
constexpr static char frFunctionsAndVariables[] = "Fonctions et variables";
constexpr static char esFunctionsAndVariables[] = "Funciones y variables";
constexpr static char deFunctionsAndVariables[] = "Funktionen und Variablen";
constexpr static char ptFunctionsAndVariables[] = "Funções e variáveis";
constexpr static char enGoto[] = "Go to";
constexpr static char frGoto[] = "Aller à";
constexpr static char esGoto[] = "Ir a";
constexpr static char deGoto[] = "Gehe zu";
constexpr static char ptGoto[] = "Ir a";
constexpr static char enGraphTab[] = "Graph";
constexpr static char frGraphTab[] = "Graphique";
constexpr static char esGraphTab[] = "Gráfico";
constexpr static char deGraphTab[] = "Graph";
constexpr static char ptGraphTab[] = "Gráfico";
constexpr static char enGreatCommonDivisor[] = "GCD";
constexpr static char frGreatCommonDivisor[] = "PGCD";
constexpr static char esGreatCommonDivisor[] = "MCD";
constexpr static char deGreatCommonDivisor[] = "ggT";
constexpr static char ptGreatCommonDivisor[] = "MDC";
constexpr static char enHardwareTestLaunch1[] = "You are starting the hardware";
constexpr static char frHardwareTestLaunch1[] = "Vous allez lancer le test usine.";
constexpr static char esHardwareTestLaunch1[] = "Esta iniciando la prueba de";
constexpr static char deHardwareTestLaunch1[] = "Sie sind dabei den Hardwaretest zu";
constexpr static char ptHardwareTestLaunch1[] = "Você vai executar o teste da planta.";
constexpr static char enHardwareTestLaunch2[] = " test. At the end of the test, you";
constexpr static char frHardwareTestLaunch2[] = "Pour en sortir vous devrez";
constexpr static char esHardwareTestLaunch2[] = "fabrica. Para quitar la prueba,";
constexpr static char deHardwareTestLaunch2[] = "starten. Um ihn wieder zu verlassen,";
constexpr static char ptHardwareTestLaunch2[] = "Para sair você tem que executar";
constexpr static char enHardwareTestLaunch3[] = "will have to reset the device and";
constexpr static char frHardwareTestLaunch3[] = "effectuer un reset qui supprimera";
constexpr static char esHardwareTestLaunch3[] = "debera resetear su equipo.";
constexpr static char deHardwareTestLaunch3[] = "muessen Sie einen Reset durchfuhren,";
constexpr static char ptHardwareTestLaunch3[] = "uma redefinição, que ira apagar";
constexpr static char enHardwareTestLaunch4[] = "all your data will be deleted.";
constexpr static char frHardwareTestLaunch4[] = "vos données.";
constexpr static char esHardwareTestLaunch4[] = "";
constexpr static char deHardwareTestLaunch4[] = "der Ihre Daten loeschen wird.";
constexpr static char ptHardwareTestLaunch4[] = "seus dados.";
constexpr static char enHideDerivativeColumn[] = "Hide the derivative function";
constexpr static char frHideDerivativeColumn[] = "Masquer la fonction derivée";
constexpr static char esHideDerivativeColumn[] = "Ocultar la derivada";
constexpr static char deHideDerivativeColumn[] = "Ableitungsfunktion ausblenden";
constexpr static char ptHideDerivativeColumn[] = "Esconder função derivada";
constexpr static char enHistogramSet[] = "Histogram settings";
constexpr static char frHistogramSet[] = "Réglage de l'histogramme";
constexpr static char esHistogramSet[] = "Parámetros del histograma";
constexpr static char deHistogramSet[] = "Einstellung des Histogramms";
constexpr static char ptHistogramSet[] = "Configurando o histograma";
constexpr static char enHistogramTab[] = "Histogram";
constexpr static char frHistogramTab[] = "Histogramme";
constexpr static char esHistogramTab[] = "Histograma";
constexpr static char deHistogramTab[] = "Histogramm";
constexpr static char ptHistogramTab[] = "Histograma";
constexpr static char enHyperbolicCosine[] = "Hyperbolic cosine";
constexpr static char frHyperbolicCosine[] = "Cosinus hyperbolique";
constexpr static char esHyperbolicCosine[] = "Coseno hiperbólico";
constexpr static char deHyperbolicCosine[] = "Kosinus hyperbolicus";
constexpr static char ptHyperbolicCosine[] = "Cosseno hiperbolico";
constexpr static char enHyperbolicSine[] = "Hyperbolic sine";
constexpr static char frHyperbolicSine[] = "Sinus hyperbolique";
constexpr static char esHyperbolicSine[] = "Seno hiperbólico";
constexpr static char deHyperbolicSine[] = "Sinus hyperbolicus";
constexpr static char ptHyperbolicSine[] = "Seno hiperbolico";
constexpr static char enHyperbolicTangent[] = "Hyperbolic tangent";
constexpr static char frHyperbolicTangent[] = "Tangente hyperbolique";
constexpr static char esHyperbolicTangent[] = "Tangente hiperbòlica";
constexpr static char deHyperbolicTangent[] = "Tangens hyperbolicus";
constexpr static char ptHyperbolicTangent[] = "Tangente hiperbolica";
constexpr static char enHyperbolicTrigonometry[] = "Hyperbolic trigonometry";
constexpr static char frHyperbolicTrigonometry[] = "Trigonométrie hyperbolique";
constexpr static char esHyperbolicTrigonometry[] = "Trigonometría hiperbólica";
constexpr static char deHyperbolicTrigonometry[] = "Hyperbelfunktionen";
constexpr static char ptHyperbolicTrigonometry[] = "Funcoes hiperbolicas";
constexpr static char enIdentity[] = "Identity matrix of size n";
constexpr static char frIdentity[] = "Matrice identité de taille n";
constexpr static char esIdentity[] = "Matriz identidad de tamaño n";
constexpr static char deIdentity[] = "Einheitsmatrix der Größe n";
constexpr static char ptIdentity[] = "Matriz identidade de ordem n";
constexpr static char enImaginaryPart[] = "Imaginary part";
constexpr static char frImaginaryPart[] = "Partie imaginaire";
constexpr static char esImaginaryPart[] = "Parte imaginaria";
constexpr static char deImaginaryPart[] = "Imaginaerteil";
constexpr static char ptImaginaryPart[] = "Parte imaginaria";
constexpr static char enImportList[] = "Import from a list";
constexpr static char frImportList[] = "Importer une liste";
constexpr static char esImportList[] = "Importar una lista";
constexpr static char deImportList[] = "Laden einer Liste";
constexpr static char ptImportList[] = "Importar de uma lista";
constexpr static char enInfiniteNumberOfSolutions[] = "There are an infinite number of solutions";
constexpr static char frInfiniteNumberOfSolutions[] = "Le système admet une infinité de solutions";
constexpr static char esInfiniteNumberOfSolutions[] = "Hay un número infinito de soluciones";
constexpr static char deInfiniteNumberOfSolutions[] = "Es gibt unendlich viele Loesungen";
constexpr static char ptInfiniteNumberOfSolutions[] = "Existe uma infinidade de soluções";
constexpr static char enInitialization[] = "Preadjustment";
constexpr static char frInitialization[] = "Initialisation";
constexpr static char esInitialization[] = "Inicialización";
constexpr static char deInitialization[] = "Initialisierung";
constexpr static char ptInitialization[] = "Inicialização";
constexpr static char enIntegral[] = "Integral";
constexpr static char frIntegral[] = "Intégrale";
constexpr static char esIntegral[] = "Integral";
constexpr static char deIntegral[] = "Integral";
constexpr static char ptIntegral[] = "Integral";
constexpr static char enInterquartileRange[] = "Interquartile range";
constexpr static char frInterquartileRange[] = "Ecart interquartile";
constexpr static char esInterquartileRange[] = "Rango intercuartilo";
constexpr static char deInterquartileRange[] = "Interquartilsabstand";
constexpr static char ptInterquartileRange[] = "Interquartil";
constexpr static char enIntersection[] = "Intersection";
constexpr static char frIntersection[] = "Intersection";
constexpr static char esIntersection[] = "Intersección";
constexpr static char deIntersection[] = "Schnittmenge";
constexpr static char ptIntersection[] = "Intersecção";
constexpr static char enInterval[] = " Interval ";
constexpr static char frInterval[] = " Intervalle ";
constexpr static char esInterval[] = " Intervalo";
constexpr static char deInterval[] = " Intervall";
constexpr static char ptInterval[] = " Intervalo";
constexpr static char enIntervalDefinition[] = "[a,b]: Interval";
constexpr static char frIntervalDefinition[] = "[a,b] : Intervalle";
constexpr static char esIntervalDefinition[] = "[a,b] : Intervalo";
constexpr static char deIntervalDefinition[] = "[a,b]: Intervall";
constexpr static char ptIntervalDefinition[] = "[a,b] : Intervalo";
constexpr static char enIntervalSet[] = "Set the interval";
constexpr static char frIntervalSet[] = "Régler l'intervalle";
constexpr static char esIntervalSet[] = "Ajustar el intervalo";
constexpr static char deIntervalSet[] = "Intervall einstellen";
constexpr static char ptIntervalSet[] = "Ajustar o intervalo";
constexpr static char enInvSort[] = "Sort descending";
constexpr static char frInvSort[] = "Tri décroissant";
constexpr static char esInvSort[] = "Clasificación descendente";
constexpr static char deInvSort[] = "Sortieren absteigend";
constexpr static char ptInvSort[] = "Ordem decrescente";
constexpr static char enInverse[] = "Inverse";
constexpr static char frInverse[] = "Inverse";
constexpr static char esInverse[] = "Inversa";
constexpr static char deInverse[] = "Inverse";
constexpr static char ptInverse[] = "Matriz inversa";
constexpr static char enInverseHyperbolicCosine[] = "Inverse hyperbolic cosine";
constexpr static char frInverseHyperbolicCosine[] = "Argument cosinus hyperbolique";
constexpr static char esInverseHyperbolicCosine[] = "Argumento coseno hiperbólico";
constexpr static char deInverseHyperbolicCosine[] = "Areakosinus hyperbolicus";
constexpr static char ptInverseHyperbolicCosine[] = "Arco cosseno hiperbolico";
constexpr static char enInverseHyperbolicSine[] = "Inverse hyperbolic sine";
constexpr static char frInverseHyperbolicSine[] = "Argument sinus hyperbolique";
constexpr static char esInverseHyperbolicSine[] = "Argumento seno hiperbólico";
constexpr static char deInverseHyperbolicSine[] = "Areasinus hyperbolicus";
constexpr static char ptInverseHyperbolicSine[] = "Arco seno hiperbolico";
constexpr static char enInverseHyperbolicTangent[] = "Inverse hyperbolic tangent";
constexpr static char frInverseHyperbolicTangent[] = "Argument tangente hyperbolique";
constexpr static char esInverseHyperbolicTangent[] = "Argumento tangente hiperbólica";
constexpr static char deInverseHyperbolicTangent[] = "Areatangens hyperbolicus";
constexpr static char ptInverseHyperbolicTangent[] = "Arco tangente hiperbolica";
constexpr static char enLambdaExponentialDefinition[] = "λ: Rate parameter";
constexpr static char frLambdaExponentialDefinition[] = "λ : Paramètre";
constexpr static char esLambdaExponentialDefinition[] = "λ : Parámetro";
constexpr static char deLambdaExponentialDefinition[] = "λ: Parameter";
constexpr static char ptLambdaExponentialDefinition[] = "λ : Parâmetro";
constexpr static char enLambdaPoissonDefinition[] = "λ: Parameter";
constexpr static char frLambdaPoissonDefinition[] = "λ : Paramètre";
constexpr static char esLambdaPoissonDefinition[] = "λ : Parámetro";
constexpr static char deLambdaPoissonDefinition[] = "λ: Parameter";
constexpr static char ptLambdaPoissonDefinition[] = "λ : Parâmetro";
constexpr static char enLanguage[] = "Language";
constexpr static char frLanguage[] = "Langue";
constexpr static char esLanguage[] = "Idioma";
constexpr static char deLanguage[] = "Sprache";
constexpr static char ptLanguage[] = "Idioma";
constexpr static char enLeastCommonMultiple[] = "LCM";
constexpr static char frLeastCommonMultiple[] = "PPCM";
constexpr static char esLeastCommonMultiple[] = "MCM";
constexpr static char deLeastCommonMultiple[] = "kgV";
constexpr static char ptLeastCommonMultiple[] = "MMC";
constexpr static char enLinear[] = "Linear";
constexpr static char frLinear[] = "Linéaire";
constexpr static char esLinear[] = "Lineal";
constexpr static char deLinear[] = "Lineare";
constexpr static char ptLinear[] = "Linear";
constexpr static char enLists[] = "List";
constexpr static char frLists[] = "Listes";
constexpr static char esLists[] = "Listas";
constexpr static char deLists[] = "Listen";
constexpr static char ptLists[] = "Listas";
constexpr static char enLogarithmic[] = "Logarithmic";
constexpr static char frLogarithmic[] = "Logarithmique";
constexpr static char esLogarithmic[] = "Logarítmica";
constexpr static char deLogarithmic[] = "Logarithmische";
constexpr static char ptLogarithmic[] = "Logarítmica";
constexpr static char enLogistic[] = "Logistic";
constexpr static char frLogistic[] = "Logistique";
constexpr static char esLogistic[] = "Logística";
constexpr static char deLogistic[] = "Logistische";
constexpr static char ptLogistic[] = "Logística";
constexpr static char enLoopsAndTests[] = "Loops and tests";
constexpr static char frLoopsAndTests[] = "Boucles et tests";
constexpr static char esLoopsAndTests[] = "Loops and tests";
constexpr static char deLoopsAndTests[] = "Schleifen und Tests";
constexpr static char ptLoopsAndTests[] = "Loops and tests";
constexpr static char enLowBattery[] = "Low battery";
constexpr static char frLowBattery[] = "Batterie faible";
constexpr static char esLowBattery[] = "Batería baja";
constexpr static char deLowBattery[] = "Batterie erschoepft";
constexpr static char ptLowBattery[] = "Bateria fraca";
constexpr static char enMatrices[] = "Matrix";
constexpr static char frMatrices[] = "Matrices";
constexpr static char esMatrices[] = "Matriz";
constexpr static char deMatrices[] = "Matrizen";
constexpr static char ptMatrices[] = "Matrizes";
constexpr static char enMaximum[] = "Maximum";
constexpr static char frMaximum[] = "Maximum";
constexpr static char esMaximum[] = "Máximo";
constexpr static char deMaximum[] = "Maximalwert";
constexpr static char ptMaximum[] = "Maximo";
constexpr static char enMean[] = "Mean";
constexpr static char frMean[] = "Moyenne";
constexpr static char esMean[] = "Media";
constexpr static char deMean[] = "Mittelwert";
constexpr static char ptMean[] = "Media";
constexpr static char enMeanDefinition[] = "μ: Mean";
constexpr static char frMeanDefinition[] = "μ : Espérance ou moyenne";
constexpr static char esMeanDefinition[] = "μ : Media";
constexpr static char deMeanDefinition[] = "μ: Erwartungswert";
constexpr static char ptMeanDefinition[] = "μ : Média";
constexpr static char enMeanDot[] = "mean";
constexpr static char frMeanDot[] = "moyen";
constexpr static char esMeanDot[] = "media";
constexpr static char deMeanDot[] = "mittel";
constexpr static char ptMeanDot[] = "media";
constexpr static char enMedian[] = "Median";
constexpr static char frMedian[] = "Médiane";
constexpr static char esMedian[] = "Mediana";
constexpr static char deMedian[] = "Median";
constexpr static char ptMedian[] = "Mediana";
constexpr static char enMinimum[] = "Minimum";
constexpr static char frMinimum[] = "Minimum";
constexpr static char esMinimum[] = "Mínimo";
constexpr static char deMinimum[] = "Mindestwert";
constexpr static char ptMinimum[] = "Minimo";
constexpr static char enModules[] = "Modules";
constexpr static char frModules[] = "Modules";
constexpr static char esModules[] = "Modules";
constexpr static char deModules[] = "Module";
constexpr static char ptModules[] = "Modules";
constexpr static char enMove[] = " Move: ";
constexpr static char frMove[] = " Déplacer : ";
constexpr static char esMove[] = " Mover : ";
constexpr static char deMove[] = " Verschieben: ";
constexpr static char ptMove[] = " Mover : ";
constexpr static char enNColumn[] = "n column";
constexpr static char frNColumn[] = "Colonne n";
constexpr static char esNColumn[] = "Columna n";
constexpr static char deNColumn[] = "n-te Spalte";
constexpr static char ptNColumn[] = "Coluna n";
constexpr static char enNEnd[] = "N end";
constexpr static char frNEnd[] = "N fin";
constexpr static char esNEnd[] = "N fin";
constexpr static char deNEnd[] = "Endwert";
constexpr static char ptNEnd[] = "N fim";
constexpr static char enNStart[] = "N start";
constexpr static char frNStart[] = "N début";
constexpr static char esNStart[] = "N inicio";
constexpr static char deNStart[] = "Startwert";
constexpr static char ptNStart[] = "N início";
constexpr static char enNameCannotStartWithNumber[] = "A name cannot start with a number";
constexpr static char frNameCannotStartWithNumber[] = "Un nom ne peut pas commencer par un chiffre";
constexpr static char esNameCannotStartWithNumber[] = "Un nombre no puede empezar con un número";
constexpr static char deNameCannotStartWithNumber[] = "Ein Name darf nicht mit einer Zahl beginnen";
constexpr static char ptNameCannotStartWithNumber[] = "Um nome não pode começar com um número";
constexpr static char enNameTaken[] = "This name has already been taken";
constexpr static char frNameTaken[] = "Ce nom est déjà utilisé";
constexpr static char esNameTaken[] = "Este nombre ya está en uso";
constexpr static char deNameTaken[] = "Dieser Name ist bereits vergeben";
constexpr static char ptNameTaken[] = "Este nome é já usado";
constexpr static char enNameTooLong[] = "This name is too long";
constexpr static char frNameTooLong[] = "Ce nom est trop long";
constexpr static char esNameTooLong[] = "Este nombre es demasiado largo";
constexpr static char deNameTooLong[] = "Der Name ist zu lang";
constexpr static char ptNameTooLong[] = "Este nome é muito longo";
constexpr static char enNewMatrix[] = "New matrix";
constexpr static char frNewMatrix[] = "Nouvelle matrice";
constexpr static char esNewMatrix[] = "Nueva matriz";
constexpr static char deNewMatrix[] = "Neue Matrix";
constexpr static char ptNewMatrix[] = "Nova matriz";
constexpr static char enNext[] = "Next";
constexpr static char frNext[] = "Suivant";
constexpr static char esNext[] = "Siguiente";
constexpr static char deNext[] = "Naechste";
constexpr static char ptNext[] = "Seguinte";
constexpr static char enNoActivatedFunction[] = "No function is turned on";
constexpr static char frNoActivatedFunction[] = "Aucune fonction activée";
constexpr static char esNoActivatedFunction[] = "Ninguna función activada";
constexpr static char deNoActivatedFunction[] = "Keine aktive Funktion";
constexpr static char ptNoActivatedFunction[] = "Sem função ativada";
constexpr static char enNoActivatedSequence[] = "No sequence is turned on";
constexpr static char frNoActivatedSequence[] = "Aucune suite activée";
constexpr static char esNoActivatedSequence[] = "Ninguna sucesión activada";
constexpr static char deNoActivatedSequence[] = "Keine aktive Folge";
constexpr static char ptNoActivatedSequence[] = "Sem sequência ativada";
constexpr static char enNoDataToPlot[] = "No data to draw";
constexpr static char frNoDataToPlot[] = "Aucune donnée à tracer";
constexpr static char esNoDataToPlot[] = "Ningunos datos que dibujar";
constexpr static char deNoDataToPlot[] = "Keine Daten zum Zeichnen";
constexpr static char ptNoDataToPlot[] = "Não ha dados para desenhar";
constexpr static char enNoFunction[] = "No function";
constexpr static char frNoFunction[] = "Aucune fonction";
constexpr static char esNoFunction[] = "Ninguna función";
constexpr static char deNoFunction[] = "Keine Funktion";
constexpr static char ptNoFunction[] = "Nenhuma função";
constexpr static char enNoFunctionToDelete[] = "No function to delete";
constexpr static char frNoFunctionToDelete[] = "Pas de fonction à supprimer";
constexpr static char esNoFunctionToDelete[] = "Ninguna función que eliminar";
constexpr static char deNoFunctionToDelete[] = "Keine Funktion zum Loeschen";
constexpr static char ptNoFunctionToDelete[] = "Sem função para eliminar";
constexpr static char enNoIntersectionFound[] = "No intersection found";
constexpr static char frNoIntersectionFound[] = "Aucune intersection trouvée";
constexpr static char esNoIntersectionFound[] = "Ninguna intersección encontrada";
constexpr static char deNoIntersectionFound[] = "Kein Schnittpunkt gefunden";
constexpr static char ptNoIntersectionFound[] = "Nenhuma intersecção encontrada";
constexpr static char enNoMaximumFound[] = "No maximum found";
constexpr static char frNoMaximumFound[] = "Aucun maximum trouvé";
constexpr static char esNoMaximumFound[] = "Níngun máximo encontrado";
constexpr static char deNoMaximumFound[] = "Kein Maximalwert gefunden";
constexpr static char ptNoMaximumFound[] = "Nenhum máximo encontrado";
constexpr static char enNoMinimumFound[] = "No minimum found";
constexpr static char frNoMinimumFound[] = "Aucun minimum trouvé";
constexpr static char esNoMinimumFound[] = "Níngun mínimo encontrado";
constexpr static char deNoMinimumFound[] = "Kein Mindestwert gefunden";
constexpr static char ptNoMinimumFound[] = "Nenhum mínimo encontrado";
constexpr static char enNoPreimageFound[] = "No inverse image found";
constexpr static char frNoPreimageFound[] = "Aucun antécédent trouvé";
constexpr static char esNoPreimageFound[] = "Ninguna imagen inversa encontrada";
constexpr static char deNoPreimageFound[] = "Kein Urbild gefunden";
constexpr static char ptNoPreimageFound[] = "Nenhuma imagem inversa encontrada";
constexpr static char enNoSequence[] = "No sequence";
constexpr static char frNoSequence[] = "Aucune suite";
constexpr static char esNoSequence[] = "Ninguna sucesión";
constexpr static char deNoSequence[] = "Keine Folge";
constexpr static char ptNoSequence[] = "Sem sequência";
constexpr static char enNoSolutionEquation[] = "The equation has no solution";
constexpr static char frNoSolutionEquation[] = "L'équation n'admet aucune solution";
constexpr static char esNoSolutionEquation[] = "La ecuación no tiene solución";
constexpr static char deNoSolutionEquation[] = "Die Gleichung hat keine Loesung";
constexpr static char ptNoSolutionEquation[] = "A equação não tem solução";
constexpr static char enNoSolutionInterval[] = "No solution found in the interval";
constexpr static char frNoSolutionInterval[] = "Aucune solution trouvée dans cet intervalle";
constexpr static char esNoSolutionInterval[] = "Ninguna solución encontrada en el intervalo";
constexpr static char deNoSolutionInterval[] = "Keine Loesung im Intervall gefunden";
constexpr static char ptNoSolutionInterval[] = "Nenhuma solução encontrada em el intervalo";
constexpr static char enNoSolutionSystem[] = "The system has no solution";
constexpr static char frNoSolutionSystem[] = "Le système n'admet aucune solution";
constexpr static char esNoSolutionSystem[] = "El sistema no tiene solución";
constexpr static char deNoSolutionSystem[] = "Das System hat keine Loesung";
constexpr static char ptNoSolutionSystem[] = "O sistema não tem solução";
constexpr static char enNoValueToCompute[] = "No values to calculate";
constexpr static char frNoValueToCompute[] = "Aucune grandeur à calculer";
constexpr static char esNoValueToCompute[] = "Ninguna medida que calcular";
constexpr static char deNoValueToCompute[] = "Keine Groesse zum Berechnen";
constexpr static char ptNoValueToCompute[] = "Nenhuma quantidade para calcular";
constexpr static char enNoZeroFound[] = "No zero found";
constexpr static char frNoZeroFound[] = "Aucun zéro trouvé";
constexpr static char esNoZeroFound[] = "Ninguna raíz encontrada";
constexpr static char deNoZeroFound[] = "Keine Nullstelle gefunden";
constexpr static char ptNoZeroFound[] = "Nenhuma raiz encontrada";
constexpr static char enNonLinearSystem[] = "The system is not linear";
constexpr static char frNonLinearSystem[] = "Le système n'est pas linéaire";
constexpr static char esNonLinearSystem[] = "El sistema no es lineal";
constexpr static char deNonLinearSystem[] = "Das System ist nicht linear";
constexpr static char ptNonLinearSystem[] = "O sistema não é linear";
constexpr static char enNormal[] = "Normal";
constexpr static char frNormal[] = "Normale";
constexpr static char esNormal[] = "Normal";
constexpr static char deNormal[] = "Normal";
constexpr static char ptNormal[] = "Normal";
constexpr static char enNormalLaw[] = "Normal distribution";
constexpr static char frNormalLaw[] = "Loi normale";
constexpr static char esNormalLaw[] = "Distribución normal";
constexpr static char deNormalLaw[] = "Normalverteilung";
constexpr static char ptNormalLaw[] = "Distribuição normal";
constexpr static char enNthRoot[] = "nth-root";
constexpr static char frNthRoot[] = "Racine n-ième";
constexpr static char esNthRoot[] = "Raíz enesima";
constexpr static char deNthRoot[] = "n-te Wurzel";
constexpr static char ptNthRoot[] = "Radiciacao";
constexpr static char enNumberOfDots[] = "Number of points";
constexpr static char frNumberOfDots[] = "Nombre de points";
constexpr static char esNumberOfDots[] = "Número de puntos";
constexpr static char deNumberOfDots[] = "Punktanzahl";
constexpr static char ptNumberOfDots[] = "Número de pontos";
constexpr static char enOk[] = "Confirm";
constexpr static char frOk[] = "Valider";
constexpr static char esOk[] = "Confirmar";
constexpr static char deOk[] = "Bestaetigen";
constexpr static char ptOk[] = "Confirmar";
constexpr static char enOnlyFirstSolutionsDisplayed0[] = "Only the first 10 solutions";
constexpr static char frOnlyFirstSolutionsDisplayed0[] = "Seulement les 10 premières";
constexpr static char esOnlyFirstSolutionsDisplayed0[] = "Sólo se muestran las";
constexpr static char deOnlyFirstSolutionsDisplayed0[] = "Es werden nur die ersten";
constexpr static char ptOnlyFirstSolutionsDisplayed0[] = "Somente as 10 primeiras";
constexpr static char enOnlyFirstSolutionsDisplayed1[] = "are displayed";
constexpr static char frOnlyFirstSolutionsDisplayed1[] = "solutions sont affichées";
constexpr static char esOnlyFirstSolutionsDisplayed1[] = "10 primeras soluciones";
constexpr static char deOnlyFirstSolutionsDisplayed1[] = "zehn Loesungen angezeigt.";
constexpr static char ptOnlyFirstSolutionsDisplayed1[] = "soluções são exibidas";
constexpr static char enOr[] = " or ";
constexpr static char frOr[] = " ou ";
constexpr static char esOr[] = " o ";
constexpr static char deOr[] = " oder ";
constexpr static char ptOr[] = " ou ";
constexpr static char enOrthonormal[] = "Orthonormal";
constexpr static char frOrthonormal[] = "Orthonormé";
constexpr static char esOrthonormal[] = "Ortonormal";
constexpr static char deOrthonormal[] = "Orthonormal";
constexpr static char ptOrthonormal[] = "Ortonormado";
constexpr static char enPermutation[] = "Permutation";
constexpr static char frPermutation[] = "Arrangement";
constexpr static char esPermutation[] = "Variación";
constexpr static char dePermutation[] = "Permutation";
constexpr static char ptPermutation[] = "Permutacao";
constexpr static char enPlot[] = "Plot graph";
constexpr static char frPlot[] = "Tracer le graphique";
constexpr static char esPlot[] = "Dibujar el gráfico";
constexpr static char dePlot[] = "Graphen zeichnen";
constexpr static char ptPlot[] = "Tracar o gráfico";
constexpr static char enPlotOptions[] = "Plot options";
constexpr static char frPlotOptions[] = "Options de la courbe";
constexpr static char esPlotOptions[] = "Opciones de la curva";
constexpr static char dePlotOptions[] = "Plotoptionen";
constexpr static char ptPlotOptions[] = "Opções da curva";
constexpr static char enPoisson[] = "Poisson";
constexpr static char frPoisson[] = "Poisson";
constexpr static char esPoisson[] = "Poisson";
constexpr static char dePoisson[] = "Poisson";
constexpr static char ptPoisson[] = "Poisson";
constexpr static char enPoissonLaw[] = "Poisson distribution";
constexpr static char frPoissonLaw[] = "Loi de Poisson";
constexpr static char esPoissonLaw[] = "Distribución de Poisson";
constexpr static char dePoissonLaw[] = "Poisson-Verteilung";
constexpr static char ptPoissonLaw[] = "Distribuição de Poisson";
constexpr static char enPolar[] = "Polar ";
constexpr static char frPolar[] = "Exponentielle ";
constexpr static char esPolar[] = "Polar ";
constexpr static char dePolar[] = "Polar ";
constexpr static char ptPolar[] = "Polar ";
constexpr static char enPolynomeHasNoRealSolution0[] = "The polynomial has no";
constexpr static char frPolynomeHasNoRealSolution0[] = "Le polynôme n'admet pas";
constexpr static char esPolynomeHasNoRealSolution0[] = "El polinomio no tiene";
constexpr static char dePolynomeHasNoRealSolution0[] = "Das Polynom hat";
constexpr static char ptPolynomeHasNoRealSolution0[] = "O polinômio não tem";
constexpr static char enPolynomeHasNoRealSolution1[] = "real root";
constexpr static char frPolynomeHasNoRealSolution1[] = "de racine réelle";
constexpr static char esPolynomeHasNoRealSolution1[] = "ninguna raíz real";
constexpr static char dePolynomeHasNoRealSolution1[] = "keine reelle Nullstelle";
constexpr static char ptPolynomeHasNoRealSolution1[] = "nenhuma raiz real";
constexpr static char enPoolMemoryFull1[] = "The working memory is full.";
constexpr static char frPoolMemoryFull1[] = "La mémoire de travail est pleine.";
constexpr static char esPoolMemoryFull1[] = "La memoria de trabajo está llena.";
constexpr static char dePoolMemoryFull1[] = "Der Arbeitsspeicher ist voll.";
constexpr static char ptPoolMemoryFull1[] = "A memória de trabalho está cheia.";
constexpr static char enPoolMemoryFull2[] = "Try again.";
constexpr static char frPoolMemoryFull2[] = "Réessayez.";
constexpr static char esPoolMemoryFull2[] = "Intente de nuevo.";
constexpr static char dePoolMemoryFull2[] = "Versuchen Sie es erneut.";
constexpr static char ptPoolMemoryFull2[] = "Tente novamente.";
constexpr static char enPower[] = "Power";
constexpr static char frPower[] = "Puissance";
constexpr static char esPower[] = "Potencial";
constexpr static char dePower[] = "Potenz";
constexpr static char ptPower[] = "Potência";
constexpr static char enPrediction[] = "Simple prediction interval";
constexpr static char frPrediction[] = "Intervalle fluctuation simple (2de)";
constexpr static char esPrediction[] = "Intervalo de predicción simple";
constexpr static char dePrediction[] = "Einfacher Schwankungsbereich";
constexpr static char ptPrediction[] = "Intervalo de previsao simples";
constexpr static char enPrediction95[] = "Prediction interval 95%";
constexpr static char frPrediction95[] = "Intervalle fluctuation 95% (Term)";
constexpr static char esPrediction95[] = "Intervalo de predicción 95%";
constexpr static char dePrediction95[] = "Schwankungsbereich 95%";
constexpr static char ptPrediction95[] = "Intervalo de previsao 95%";
constexpr static char enPreimage[] = "Inverse image";
constexpr static char frPreimage[] = "Antécédent";
constexpr static char esPreimage[] = "Imagen inversa";
constexpr static char dePreimage[] = "Urbild";
constexpr static char ptPreimage[] = "Imagem inversa";
constexpr static char enPrimeFactorDecomposition[] = "Integer factorization";
constexpr static char frPrimeFactorDecomposition[] = "Décomposition en facteurs premiers";
constexpr static char esPrimeFactorDecomposition[] = "Factorización de enteros";
constexpr static char dePrimeFactorDecomposition[] = "Primfaktorzerlegung";
constexpr static char ptPrimeFactorDecomposition[] = "Fatoração de inteiros";
constexpr static char enProbaApp[] = "Probability";
constexpr static char frProbaApp[] = "Probabilités";
constexpr static char esProbaApp[] = "Probabilidad";
constexpr static char deProbaApp[] = "Wahrsch.";
constexpr static char ptProbaApp[] = "Probabilidade";
constexpr static char enProbaAppCapital[] = "PROBABILITY";
constexpr static char frProbaAppCapital[] = "PROBABILITES";
constexpr static char esProbaAppCapital[] = "PROBABILIDAD";
constexpr static char deProbaAppCapital[] = "WAHRSCHEINLICHKEIT";
constexpr static char ptProbaAppCapital[] = "PROBABILIDADE";
constexpr static char enProbability[] = "Combinatorics";
constexpr static char frProbability[] = "Dénombrement";
constexpr static char esProbability[] = "Combinatoria";
constexpr static char deProbability[] = "Kombinatorik";
constexpr static char ptProbability[] = "Combinatoria";
constexpr static char enProduct[] = "Product";
constexpr static char frProduct[] = "Produit";
constexpr static char esProduct[] = "Productorio";
constexpr static char deProduct[] = "Produkt";
constexpr static char ptProduct[] = "Produto";
constexpr static char enPython1J[] = "Imaginary i";
constexpr static char frPython1J[] = "i complexe";
constexpr static char esPython1J[] = "Imaginary i";
constexpr static char dePython1J[] = "Imaginaeres i";
constexpr static char ptPython1J[] = "Imaginary i";
constexpr static char enPythonAbs[] = "Absolute value/Magnitude";
constexpr static char frPythonAbs[] = "Valeur absolue/Module";
constexpr static char esPythonAbs[] = "Absolute value/Magnitude";
constexpr static char dePythonAbs[] = "Absolute/r Wert/Groesse";
constexpr static char ptPythonAbs[] = "Absolute value/Magnitude";
constexpr static char enPythonAcos[] = "Arc cosine";
constexpr static char frPythonAcos[] = "Arc cosinus";
constexpr static char esPythonAcos[] = "Arc cosine";
constexpr static char dePythonAcos[] = "Arkuskosinus";
constexpr static char ptPythonAcos[] = "Arc cosine";
constexpr static char enPythonAcosh[] = "Arc hyperbolic cosine";
constexpr static char frPythonAcosh[] = "Arc cosinus hyperbolique";
constexpr static char esPythonAcosh[] = "Arc hyperbolic cosine";
constexpr static char dePythonAcosh[] = "Hyperbelkosinus";
constexpr static char ptPythonAcosh[] = "Arc hyperbolic cosine";
constexpr static char enPythonAmpersand[] = "Bitwise and";
constexpr static char frPythonAmpersand[] = "Et logique";
constexpr static char esPythonAmpersand[] = "Bitwise and";
constexpr static char dePythonAmpersand[] = "Bitweise und";
constexpr static char ptPythonAmpersand[] = "Bitwise and";
constexpr static char enPythonAsin[] = "Arc sine";
constexpr static char frPythonAsin[] = "Arc sinus";
constexpr static char esPythonAsin[] = "Arc sine";
constexpr static char dePythonAsin[] = "Arkussinus";
constexpr static char ptPythonAsin[] = "Arc sine";
constexpr static char enPythonAsinh[] = "Arc hyperbolic sine";
constexpr static char frPythonAsinh[] = "Arc sinus hyperbolique";
constexpr static char esPythonAsinh[] = "Arc hyperbolic sine";
constexpr static char dePythonAsinh[] = "Hyperbelsinus";
constexpr static char ptPythonAsinh[] = "Arc hyperbolic sine";
constexpr static char enPythonAtan[] = "Arc tangent";
constexpr static char frPythonAtan[] = "Arc tangente";
constexpr static char esPythonAtan[] = "Arc tangent";
constexpr static char dePythonAtan[] = "Arkustangens";
constexpr static char ptPythonAtan[] = "Arc tangent";
constexpr static char enPythonAtan2[] = "Return arctan(y/x)";
constexpr static char frPythonAtan2[] = "Calcul de arctan(y/x)";
constexpr static char esPythonAtan2[] = "Return arctan(y/x)";
constexpr static char dePythonAtan2[] = "Gib arctan(y/x)";
constexpr static char ptPythonAtan2[] = "Return arctan(y/x)";
constexpr static char enPythonAtanh[] = "Arc hyperbolic tangent";
constexpr static char frPythonAtanh[] = "Arc tangente hyperbolique";
constexpr static char esPythonAtanh[] = "Arc hyperbolic tangent";
constexpr static char dePythonAtanh[] = "Hyperbeltangens";
constexpr static char ptPythonAtanh[] = "Arc hyperbolic tangent";
constexpr static char enPythonBin[] = "Convert integer to binary";
constexpr static char frPythonBin[] = "Conversion d'un entier en binaire";
constexpr static char esPythonBin[] = "Convert integer to binary";
constexpr static char dePythonBin[] = "Ganzzahl nach binaer konvertieren";
constexpr static char ptPythonBin[] = "Convert integer to binary";
constexpr static char enPythonCeil[] = "Ceiling";
constexpr static char frPythonCeil[] = "Plafond";
constexpr static char esPythonCeil[] = "Ceiling";
constexpr static char dePythonCeil[] = "Aufrundung";
constexpr static char ptPythonCeil[] = "Ceiling";
constexpr static char enPythonChoice[] = "Random number in the list";
constexpr static char frPythonChoice[] = "Nombre aléatoire dans la liste";
constexpr static char esPythonChoice[] = "Random number in the list";
constexpr static char dePythonChoice[] = "Zufallszahl aus der Liste";
constexpr static char ptPythonChoice[] = "Random number in the list";
constexpr static char enPythonCmathFunction[] = "cmath module function prefix";
constexpr static char frPythonCmathFunction[] = "Préfixe fonction du module cmath";
constexpr static char esPythonCmathFunction[] = "cmath module function prefix";
constexpr static char dePythonCmathFunction[] = "cmath-Modul-Funktionspraefix";
constexpr static char ptPythonCmathFunction[] = "cmath module function prefix";
constexpr static char enPythonColor[] = "Define a rgb color";
constexpr static char frPythonColor[] = "Définit une couleur rgb";
constexpr static char esPythonColor[] = "Define a rgb color";
constexpr static char dePythonColor[] = "Definiere eine RGB-Farbe";
constexpr static char ptPythonColor[] = "Define a rgb color";
constexpr static char enPythonComplex[] = "Return a+ib";
constexpr static char frPythonComplex[] = "Retourne a+ib";
constexpr static char esPythonComplex[] = "Return a+ib";
constexpr static char dePythonComplex[] = "a+ib zurueckgeben";
constexpr static char ptPythonComplex[] = "Return a+ib";
constexpr static char enPythonConstantE[] = "2.718281828459046";
constexpr static char frPythonConstantE[] = "2.718281828459045";
constexpr static char esPythonConstantE[] = "2.718281828459046";
constexpr static char dePythonConstantE[] = "2.718281828459046";
constexpr static char ptPythonConstantE[] = "2.718281828459046";
constexpr static char enPythonConstantPi[] = "3.141592653589794";
constexpr static char frPythonConstantPi[] = "3.141592653589793";
constexpr static char esPythonConstantPi[] = "3.141592653589794";
constexpr static char dePythonConstantPi[] = "3.141592653589794";
constexpr static char ptPythonConstantPi[] = "3.141592653589794";
constexpr static char enPythonCopySign[] = "Return x with the sign of y";
constexpr static char frPythonCopySign[] = "Retourne x avec le signe de y";
constexpr static char esPythonCopySign[] = "Return x with the sign of y";
constexpr static char dePythonCopySign[] = "Return x with the sign of y";
constexpr static char ptPythonCopySign[] = "Return x with the sign of y";
constexpr static char enPythonCos[] = "Cosine";
constexpr static char frPythonCos[] = "Cosinus";
constexpr static char esPythonCos[] = "Cosine";
constexpr static char dePythonCos[] = "Kosinus";
constexpr static char ptPythonCos[] = "Cosine";
constexpr static char enPythonCosh[] = "Hyperbolic cosine";
constexpr static char frPythonCosh[] = "Cosinus hyperbolique";
constexpr static char esPythonCosh[] = "Hyperbolic cosine";
constexpr static char dePythonCosh[] = "Hyperbolic cosine";
constexpr static char ptPythonCosh[] = "Hyperbolic cosine";
constexpr static char enPythonDegrees[] = "Convert x from radians to degrees";
constexpr static char frPythonDegrees[] = "Conversion de radians en degrés";
constexpr static char esPythonDegrees[] = "Convert x from radians to degrees";
constexpr static char dePythonDegrees[] = "Convert x from radians to degrees";
constexpr static char ptPythonDegrees[] = "Convert x from radians to degrees";
constexpr static char enPythonDivMod[] = "Quotient and remainder";
constexpr static char frPythonDivMod[] = "Quotient et reste";
constexpr static char esPythonDivMod[] = "Quotient and remainder";
constexpr static char dePythonDivMod[] = "Quotient and remainder";
constexpr static char ptPythonDivMod[] = "Quotient and remainder";
constexpr static char enPythonDrawString[] = "Display a text from pixel (x,y)";
constexpr static char frPythonDrawString[] = "Affiche un texte au pixel (x,y)";
constexpr static char esPythonDrawString[] = "Display a text from pixel (x,y)";
constexpr static char dePythonDrawString[] = "Display a text from pixel (x,y)";
constexpr static char ptPythonDrawString[] = "Display a text from pixel (x,y)";
constexpr static char enPythonErf[] = "Error function";
constexpr static char frPythonErf[] = "Fonction d'erreur";
constexpr static char esPythonErf[] = "Error function";
constexpr static char dePythonErf[] = "Error function";
constexpr static char ptPythonErf[] = "Error function";
constexpr static char enPythonErfc[] = "Complementary error function";
constexpr static char frPythonErfc[] = "Fonction d'erreur complémentaire";
constexpr static char esPythonErfc[] = "Complementary error function";
constexpr static char dePythonErfc[] = "Complementary error function";
constexpr static char ptPythonErfc[] = "Complementary error function";
constexpr static char enPythonEval[] = "Returns the evaluated expression";
constexpr static char frPythonEval[] = "Evalue l'expression en argument ";
constexpr static char esPythonEval[] = "Returns the evaluated expression";
constexpr static char dePythonEval[] = "Returns the evaluated expression";
constexpr static char ptPythonEval[] = "Returns the evaluated expression";
constexpr static char enPythonExp[] = "Exponential function";
constexpr static char frPythonExp[] = "Fonction exponentielle";
constexpr static char esPythonExp[] = "Exponential function";
constexpr static char dePythonExp[] = "Exponential function";
constexpr static char ptPythonExp[] = "Exponential function";
constexpr static char enPythonExpm1[] = "Compute exp(x)-1";
constexpr static char frPythonExpm1[] = "Calcul de exp(x)-1";
constexpr static char esPythonExpm1[] = "Compute exp(x)-1";
constexpr static char dePythonExpm1[] = "Compute exp(x)-1";
constexpr static char ptPythonExpm1[] = "Compute exp(x)-1";
constexpr static char enPythonFabs[] = "Absolute value";
constexpr static char frPythonFabs[] = "Valeur absolue";
constexpr static char esPythonFabs[] = "Absolute value";
constexpr static char dePythonFabs[] = "Absolute value";
constexpr static char ptPythonFabs[] = "Absolute value";
constexpr static char enPythonFillRect[] = "Fill a rectangle at pixel (x,y)";
constexpr static char frPythonFillRect[] = "Remplit un rectangle";
constexpr static char esPythonFillRect[] = "Fill a rectangle at pixel (x,y)";
constexpr static char dePythonFillRect[] = "Fill a rectangle at pixel (x,y)";
constexpr static char ptPythonFillRect[] = "Fill a rectangle at pixel (x,y)";
constexpr static char enPythonFloat[] = "Convert x to a float";
constexpr static char frPythonFloat[] = "Conversion en flottant";
constexpr static char esPythonFloat[] = "Convert x to a float";
constexpr static char dePythonFloat[] = "Convert x to a float";
constexpr static char ptPythonFloat[] = "Convert x to a float";
constexpr static char enPythonFloor[] = "Floor";
constexpr static char frPythonFloor[] = "Partie entière";
constexpr static char esPythonFloor[] = "Floor";
constexpr static char dePythonFloor[] = "Floor";
constexpr static char ptPythonFloor[] = "Floor";
constexpr static char enPythonFmod[] = "a modulo b";
constexpr static char frPythonFmod[] = "a modulo b";
constexpr static char esPythonFmod[] = "a modulo b";
constexpr static char dePythonFmod[] = "a modulo b";
constexpr static char ptPythonFmod[] = "a modulo b";
constexpr static char enPythonFrExp[] = "Mantissa and exponent of x";
constexpr static char frPythonFrExp[] = "Mantisse et exposant de x : (m,e)";
constexpr static char esPythonFrExp[] = "Mantissa and exponent of x";
constexpr static char dePythonFrExp[] = "Mantissa and exponent of x";
constexpr static char ptPythonFrExp[] = "Mantissa and exponent of x";
constexpr static char enPythonGamma[] = "Gamma function";
constexpr static char frPythonGamma[] = "Fonction gamma";
constexpr static char esPythonGamma[] = "Gamma function";
constexpr static char dePythonGamma[] = "Gamma function";
constexpr static char ptPythonGamma[] = "Gamma function";
constexpr static char enPythonGetPixel[] = "Return pixel (x,y) color";
constexpr static char frPythonGetPixel[] = "Renvoie la couleur du pixel (x,y)";
constexpr static char esPythonGetPixel[] = "Return pixel (x,y) color";
constexpr static char dePythonGetPixel[] = "Return pixel (x,y) color";
constexpr static char ptPythonGetPixel[] = "Return pixel (x,y) color";
constexpr static char enPythonGetrandbits[] = "Integer with k random bits";
constexpr static char frPythonGetrandbits[] = "Nombre aléatoire sur k bits";
constexpr static char esPythonGetrandbits[] = "Integer with k random bits";
constexpr static char dePythonGetrandbits[] = "Integer with k random bits";
constexpr static char ptPythonGetrandbits[] = "Integer with k random bits";
constexpr static char enPythonHex[] = "Convert integer to hexadecimal";
constexpr static char frPythonHex[] = "Conversion entier en hexadécimal";
constexpr static char esPythonHex[] = "Convert integer to hexadecimal";
constexpr static char dePythonHex[] = "Convert integer to hexadecimal";
constexpr static char ptPythonHex[] = "Convert integer to hexadecimal";
constexpr static char enPythonImag[] = "Imaginary part of z";
constexpr static char frPythonImag[] = "Partie imaginaire de z";
constexpr static char esPythonImag[] = "Imaginary part of z";
constexpr static char dePythonImag[] = "Imaginaerteil von z";
constexpr static char ptPythonImag[] = "Imaginary part of z";
constexpr static char enPythonImportCmath[] = "Import cmath module";
constexpr static char frPythonImportCmath[] = "Importation du module cmath";
constexpr static char esPythonImportCmath[] = "Import cmath module";
constexpr static char dePythonImportCmath[] = "Import cmath module";
constexpr static char ptPythonImportCmath[] = "Import cmath module";
constexpr static char enPythonImportFromCmath[] = "Import cmath module";
constexpr static char frPythonImportFromCmath[] = "Importation du module cmath";
constexpr static char esPythonImportFromCmath[] = "Import cmath module";
constexpr static char dePythonImportFromCmath[] = "Import cmath module";
constexpr static char ptPythonImportFromCmath[] = "Import cmath module";
constexpr static char enPythonImportFromKandinsky[] = "Import kandinsky module";
constexpr static char frPythonImportFromKandinsky[] = "Importation du module kandinsky";
constexpr static char esPythonImportFromKandinsky[] = "Import kandinsky module";
constexpr static char dePythonImportFromKandinsky[] = "Import kandinsky module";
constexpr static char ptPythonImportFromKandinsky[] = "Import kandinsky module";
constexpr static char enPythonImportFromMath[] = "Import math module";
constexpr static char frPythonImportFromMath[] = "Importation du module math";
constexpr static char esPythonImportFromMath[] = "Import math module";
constexpr static char dePythonImportFromMath[] = "Import math module";
constexpr static char ptPythonImportFromMath[] = "Import math module";
constexpr static char enPythonImportFromRandom[] = "Import random module";
constexpr static char frPythonImportFromRandom[] = "Importation du module random";
constexpr static char esPythonImportFromRandom[] = "Import random module";
constexpr static char dePythonImportFromRandom[] = "Import random module";
constexpr static char ptPythonImportFromRandom[] = "Import random module";
constexpr static char enPythonImportFromTurtle[] = "Import turtle module";
constexpr static char frPythonImportFromTurtle[] = "Importation du module turtle";
constexpr static char esPythonImportFromTurtle[] = "Import turtle module";
constexpr static char dePythonImportFromTurtle[] = "Import turtle module";
constexpr static char ptPythonImportFromTurtle[] = "Import turtle module";
constexpr static char enPythonImportKandinsky[] = "Import kandinsky module";
constexpr static char frPythonImportKandinsky[] = "Importation du module kandinsky";
constexpr static char esPythonImportKandinsky[] = "Import kandinsky module";
constexpr static char dePythonImportKandinsky[] = "Import kandinsky module";
constexpr static char ptPythonImportKandinsky[] = "Import kandinsky module";
constexpr static char enPythonImportMath[] = "Import math module";
constexpr static char frPythonImportMath[] = "Importation du module math";
constexpr static char esPythonImportMath[] = "Import math module";
constexpr static char dePythonImportMath[] = "Import math module";
constexpr static char ptPythonImportMath[] = "Import math module";
constexpr static char enPythonImportRandom[] = "Import random module";
constexpr static char frPythonImportRandom[] = "Importation du module random";
constexpr static char esPythonImportRandom[] = "Import random module";
constexpr static char dePythonImportRandom[] = "Import random module";
constexpr static char ptPythonImportRandom[] = "Import random module";
constexpr static char enPythonImportTurtle[] = "Import turtle module";
constexpr static char frPythonImportTurtle[] = "Importation du module turtle";
constexpr static char esPythonImportTurtle[] = "Import turtle module";
constexpr static char dePythonImportTurtle[] = "Import turtle module";
constexpr static char ptPythonImportTurtle[] = "Import turtle module";
constexpr static char enPythonInput[] = "Prompt a value";
constexpr static char frPythonInput[] = "Entrer une valeur";
constexpr static char esPythonInput[] = "Prompt a value";
constexpr static char dePythonInput[] = "Prompt a value";
constexpr static char ptPythonInput[] = "Prompt a value";
constexpr static char enPythonInt[] = "Convert x to an integer";
constexpr static char frPythonInt[] = "Conversion en entier";
constexpr static char esPythonInt[] = "Convert x to an integer";
constexpr static char dePythonInt[] = "Convert x to an integer";
constexpr static char ptPythonInt[] = "Convert x to an integer";
constexpr static char enPythonIsFinite[] = "Check if x is finite";
constexpr static char frPythonIsFinite[] = "Teste si x est fini";
constexpr static char esPythonIsFinite[] = "Check if x is finite";
constexpr static char dePythonIsFinite[] = "Check if x is finite";
constexpr static char ptPythonIsFinite[] = "Check if x is finite";
constexpr static char enPythonIsInfinite[] = "Check if x is infinity";
constexpr static char frPythonIsInfinite[] = "Teste si x est infini";
constexpr static char esPythonIsInfinite[] = "Check if x is infinity";
constexpr static char dePythonIsInfinite[] = "Check if x is infinity";
constexpr static char ptPythonIsInfinite[] = "Check if x is infinity";
constexpr static char enPythonIsNaN[] = "Check if x is a NaN";
constexpr static char frPythonIsNaN[] = "Teste si x est NaN";
constexpr static char esPythonIsNaN[] = "Check if x is a NaN";
constexpr static char dePythonIsNaN[] = "Check if x is a NaN";
constexpr static char ptPythonIsNaN[] = "Check if x is a NaN";
constexpr static char enPythonKandinskyFunction[] = "kandinsky module function prefix";
constexpr static char frPythonKandinskyFunction[] = "Préfixe fonction module kandinsky";
constexpr static char esPythonKandinskyFunction[] = "kandinsky module function prefix";
constexpr static char dePythonKandinskyFunction[] = "kandinsky module function prefix";
constexpr static char ptPythonKandinskyFunction[] = "kandinsky module function prefix";
constexpr static char enPythonLF[] = "Line feed";
constexpr static char frPythonLF[] = "Saut à la ligne";
constexpr static char esPythonLF[] = "Line feed";
constexpr static char dePythonLF[] = "Zeilenvorschub";
constexpr static char ptPythonLF[] = "Line feed";
constexpr static char enPythonLdexp[] = "Return x*(2**i), inverse of frexp";
constexpr static char frPythonLdexp[] = "Inverse de frexp : x*(2**i)";
constexpr static char esPythonLdexp[] = "Return x*(2**i), inverse of frexp";
constexpr static char dePythonLdexp[] = "Return x*(2**i), inverse of frexp";
constexpr static char ptPythonLdexp[] = "Return x*(2**i), inverse of frexp";
constexpr static char enPythonLength[] = "Length of an object";
constexpr static char frPythonLength[] = "Longueur d'un objet";
constexpr static char esPythonLength[] = "Length of an object";
constexpr static char dePythonLength[] = "Length of an object";
constexpr static char ptPythonLength[] = "Length of an object";
constexpr static char enPythonLgamma[] = "Log-gamma function";
constexpr static char frPythonLgamma[] = "Logarithme de la fonction gamma";
constexpr static char esPythonLgamma[] = "Log-gamma function";
constexpr static char dePythonLgamma[] = "Log-gamma function";
constexpr static char ptPythonLgamma[] = "Log-gamma function";
constexpr static char enPythonLog[] = "Logarithm to base a";
constexpr static char frPythonLog[] = "Logarithme base a";
constexpr static char esPythonLog[] = "Logarithm to base a";
constexpr static char dePythonLog[] = "Logarithm to base a";
constexpr static char ptPythonLog[] = "Logarithm to base a";
constexpr static char enPythonLog10[] = "Logarithm to base 10";
constexpr static char frPythonLog10[] = "Logarithme base 10";
constexpr static char esPythonLog10[] = "Logarithm to base 10";
constexpr static char dePythonLog10[] = "Logarithm to base 10";
constexpr static char ptPythonLog10[] = "Logarithm to base 10";
constexpr static char enPythonLog2[] = "Logarithm to base 2";
constexpr static char frPythonLog2[] = "Logarithme base 2";
constexpr static char esPythonLog2[] = "Logarithm to base 2";
constexpr static char dePythonLog2[] = "Logarithm to base 2";
constexpr static char ptPythonLog2[] = "Logarithm to base 2";
constexpr static char enPythonMathFunction[] = "math module function prefix";
constexpr static char frPythonMathFunction[] = "Préfixe fonction du module math";
constexpr static char esPythonMathFunction[] = "math module function prefix";
constexpr static char dePythonMathFunction[] = "math module function prefix";
constexpr static char ptPythonMathFunction[] = "math module function prefix";
constexpr static char enPythonMax[] = "Maximum";
constexpr static char frPythonMax[] = "Maximum";
constexpr static char esPythonMax[] = "Maximum";
constexpr static char dePythonMax[] = "Maximum";
constexpr static char ptPythonMax[] = "Maximum";
constexpr static char enPythonMin[] = "Minimum";
constexpr static char frPythonMin[] = "Minimum";
constexpr static char esPythonMin[] = "Minimum";
constexpr static char dePythonMin[] = "Minimum";
constexpr static char ptPythonMin[] = "Minimum";
constexpr static char enPythonModf[] = "Fractional and integer parts of x";
constexpr static char frPythonModf[] = "Parties fractionnaire et entière";
constexpr static char esPythonModf[] = "Fractional and integer parts of x";
constexpr static char dePythonModf[] = "Fractional and integer parts of x";
constexpr static char ptPythonModf[] = "Fractional and integer parts of x";
constexpr static char enPythonOct[] = "Convert integer to octal";
constexpr static char frPythonOct[] = "Conversion en octal";
constexpr static char esPythonOct[] = "Convert integer to octal";
constexpr static char dePythonOct[] = "Convert integer to octal";
constexpr static char ptPythonOct[] = "Convert integer to octal";
constexpr static char enPythonPercent[] = "Modulo";
constexpr static char frPythonPercent[] = "Modulo";
constexpr static char esPythonPercent[] = "Modulo";
constexpr static char dePythonPercent[] = "Modulo";
constexpr static char ptPythonPercent[] = "Modulo";
constexpr static char enPythonPhase[] = "Phase of z";
constexpr static char frPythonPhase[] = "Argument de z";
constexpr static char esPythonPhase[] = "Phase of z";
constexpr static char dePythonPhase[] = "Phase of z";
constexpr static char ptPythonPhase[] = "Phase of z";
constexpr static char enPythonPolar[] = "z in polar coordinates";
constexpr static char frPythonPolar[] = "Conversion en polaire";
constexpr static char esPythonPolar[] = "z in polar coordinates";
constexpr static char dePythonPolar[] = "z in polar coordinates";
constexpr static char ptPythonPolar[] = "z in polar coordinates";
constexpr static char enPythonPound[] = "Comment";
constexpr static char frPythonPound[] = "Commentaire";
constexpr static char esPythonPound[] = "Comment";
constexpr static char dePythonPound[] = "Kommentar";
constexpr static char ptPythonPound[] = "Comment";
constexpr static char enPythonPower[] = "x raised to the power y";
constexpr static char frPythonPower[] = "x à la puissance y";
constexpr static char esPythonPower[] = "x raised to the power y";
constexpr static char dePythonPower[] = "x raised to the power y";
constexpr static char ptPythonPower[] = "x raised to the power y";
constexpr static char enPythonPrint[] = "Print object";
constexpr static char frPythonPrint[] = "Affiche l'objet";
constexpr static char esPythonPrint[] = "Print object";
constexpr static char dePythonPrint[] = "Print object";
constexpr static char ptPythonPrint[] = "Print object";
constexpr static char enPythonRadians[] = "Convert x from degrees to radians";
constexpr static char frPythonRadians[] = "Conversion de degrés en radians";
constexpr static char esPythonRadians[] = "Convert x from degrees to radians";
constexpr static char dePythonRadians[] = "Convert x from degrees to radians";
constexpr static char ptPythonRadians[] = "Convert x from degrees to radians";
constexpr static char enPythonRandint[] = "Random integer in [a,b]";
constexpr static char frPythonRandint[] = "Entier aléatoire dans [a,b]";
constexpr static char esPythonRandint[] = "Random integer in [a,b]";
constexpr static char dePythonRandint[] = "Random integer in [a,b]";
constexpr static char ptPythonRandint[] = "Random integer in [a,b]";
constexpr static char enPythonRandom[] = "Floating point number in [0,1[";
constexpr static char frPythonRandom[] = "Nombre décimal dans [0,1[";
constexpr static char esPythonRandom[] = "Floating point number in [0,1[";
constexpr static char dePythonRandom[] = "Floating point number in [0,1[";
constexpr static char ptPythonRandom[] = "Floating point number in [0,1[";
constexpr static char enPythonRandomFunction[] = "random module function prefix";
constexpr static char frPythonRandomFunction[] = "Préfixe fonction du module random";
constexpr static char esPythonRandomFunction[] = "random module function prefix";
constexpr static char dePythonRandomFunction[] = "random module function prefix";
constexpr static char ptPythonRandomFunction[] = "random module function prefix";
constexpr static char enPythonRandrange[] = "Random number in range(start, stop)";
constexpr static char frPythonRandrange[] = "Nombre dans range(start, stop)";
constexpr static char esPythonRandrange[] = "Random number in range(start, stop)";
constexpr static char dePythonRandrange[] = "Random number in range(start, stop)";
constexpr static char ptPythonRandrange[] = "Random number in range(start, stop)";
constexpr static char enPythonRangeStartStop[] = "List from start to stop-1";
constexpr static char frPythonRangeStartStop[] = "Liste de start à stop-1";
constexpr static char esPythonRangeStartStop[] = "List from start to stop-1";
constexpr static char dePythonRangeStartStop[] = "List from start to stop-1";
constexpr static char ptPythonRangeStartStop[] = "List from start to stop-1";
constexpr static char enPythonRangeStop[] = "List from 0 to stop-1";
constexpr static char frPythonRangeStop[] = "Liste de 0 à stop-1";
constexpr static char esPythonRangeStop[] = "List from 0 to stop-1";
constexpr static char dePythonRangeStop[] = "List from 0 to stop-1";
constexpr static char ptPythonRangeStop[] = "List from 0 to stop-1";
constexpr static char enPythonReal[] = "Real part of z";
constexpr static char frPythonReal[] = "Partie réelle de z";
constexpr static char esPythonReal[] = "Real part of z";
constexpr static char dePythonReal[] = "Realteil von z";
constexpr static char ptPythonReal[] = "Real part of z";
constexpr static char enPythonRect[] = "z in cartesian coordinates";
constexpr static char frPythonRect[] = "Conversion en algébrique";
constexpr static char esPythonRect[] = "z in cartesian coordinates";
constexpr static char dePythonRect[] = "z in cartesian coordinates";
constexpr static char ptPythonRect[] = "z in cartesian coordinates";
constexpr static char enPythonRound[] = "Round to n digits";
constexpr static char frPythonRound[] = "Arrondi n chiffres";
constexpr static char esPythonRound[] = "Round to n digits";
constexpr static char dePythonRound[] = "Round to n digits";
constexpr static char ptPythonRound[] = "Round to n digits";
constexpr static char enPythonSeed[] = "Initialize random number generator";
constexpr static char frPythonSeed[] = "Initialiser générateur aléatoire";
constexpr static char esPythonSeed[] = "Initialize random number generator";
constexpr static char dePythonSeed[] = "Initialize random number generator";
constexpr static char ptPythonSeed[] = "Initialize random number generator";
constexpr static char enPythonSetPixel[] = "Color pixel (x,y)";
constexpr static char frPythonSetPixel[] = "Colore le pixel (x,y)";
constexpr static char esPythonSetPixel[] = "Color pixel (x,y)";
constexpr static char dePythonSetPixel[] = "Color pixel (x,y)";
constexpr static char ptPythonSetPixel[] = "Color pixel (x,y)";
constexpr static char enPythonSin[] = "Sine";
constexpr static char frPythonSin[] = "Sinus";
constexpr static char esPythonSin[] = "Sine";
constexpr static char dePythonSin[] = "Sine";
constexpr static char ptPythonSin[] = "Sine";
constexpr static char enPythonSingleQuote[] = "Single quote";
constexpr static char frPythonSingleQuote[] = "Apostrophe";
constexpr static char esPythonSingleQuote[] = "Single quote";
constexpr static char dePythonSingleQuote[] = "Einfaches Anfuehrungszeichen";
constexpr static char ptPythonSingleQuote[] = "Single quote";
constexpr static char enPythonSinh[] = "Hyperbolic sine";
constexpr static char frPythonSinh[] = "Sinus hyperbolique";
constexpr static char esPythonSinh[] = "Hyperbolic sine";
constexpr static char dePythonSinh[] = "Hyperbolic sine";
constexpr static char ptPythonSinh[] = "Hyperbolic sine";
constexpr static char enPythonSorted[] = "Sort a list";
constexpr static char frPythonSorted[] = "Tri d'une liste";
constexpr static char esPythonSorted[] = "Sort a list";
constexpr static char dePythonSorted[] = "Sort a list";
constexpr static char ptPythonSorted[] = "Sort a list";
constexpr static char enPythonSqrt[] = "Square root";
constexpr static char frPythonSqrt[] = "Racine carrée";
constexpr static char esPythonSqrt[] = "Square root";
constexpr static char dePythonSqrt[] = "Square root";
constexpr static char ptPythonSqrt[] = "Square root";
constexpr static char enPythonSum[] = "Sum the items of a list";
constexpr static char frPythonSum[] = "Somme des éléments d'une liste";
constexpr static char esPythonSum[] = "Sum the items of a list";
constexpr static char dePythonSum[] = "Sum the items of a list";
constexpr static char ptPythonSum[] = "Sum the items of a list";
constexpr static char enPythonSymbolExp[] = "Bitwise exclusive or";
constexpr static char frPythonSymbolExp[] = "Ou exclusif logique";
constexpr static char esPythonSymbolExp[] = "Bitwise exclusive or";
constexpr static char dePythonSymbolExp[] = "Bitweise exklusiv oder";
constexpr static char ptPythonSymbolExp[] = "Bitwise exclusive or";
constexpr static char enPythonTab[] = "Tabulation";
constexpr static char frPythonTab[] = "Tabulation";
constexpr static char esPythonTab[] = "Tabulation";
constexpr static char dePythonTab[] = "Tabulator";
constexpr static char ptPythonTab[] = "Tabulation";
constexpr static char enPythonTan[] = "Tangent";
constexpr static char frPythonTan[] = "Tangente";
constexpr static char esPythonTan[] = "Tangent";
constexpr static char dePythonTan[] = "Tangent";
constexpr static char ptPythonTan[] = "Tangent";
constexpr static char enPythonTanh[] = "Hyperbolic tangent";
constexpr static char frPythonTanh[] = "Tangente hyperbolique";
constexpr static char esPythonTanh[] = "Hyperbolic tangent";
constexpr static char dePythonTanh[] = "Hyperbolic tangent";
constexpr static char ptPythonTanh[] = "Hyperbolic tangent";
constexpr static char enPythonTrunc[] = "x truncated to an integer";
constexpr static char frPythonTrunc[] = "Troncature entière";
constexpr static char esPythonTrunc[] = "x truncated to an integer";
constexpr static char dePythonTrunc[] = "x truncated to an integer";
constexpr static char ptPythonTrunc[] = "x truncated to an integer";
constexpr static char enPythonTurtleBackward[] = "Move backward by x pixels";
constexpr static char frPythonTurtleBackward[] = "Recule de x pixels";
constexpr static char esPythonTurtleBackward[] = "Move backward by x pixels";
constexpr static char dePythonTurtleBackward[] = "Move backward by x pixels";
constexpr static char ptPythonTurtleBackward[] = "Move backward by x pixels";
constexpr static char enPythonTurtleBlack[] = "Black color";
constexpr static char frPythonTurtleBlack[] = "Couleur noire";
constexpr static char esPythonTurtleBlack[] = "Black color";
constexpr static char dePythonTurtleBlack[] = "Black color";
constexpr static char ptPythonTurtleBlack[] = "Black color";
constexpr static char enPythonTurtleBlue[] = "Blue color";
constexpr static char frPythonTurtleBlue[] = "Couleur bleue";
constexpr static char esPythonTurtleBlue[] = "Blue color";
constexpr static char dePythonTurtleBlue[] = "Blue color";
constexpr static char ptPythonTurtleBlue[] = "Blue color";
constexpr static char enPythonTurtleBrown[] = "Brown color";
constexpr static char frPythonTurtleBrown[] = "Couleur marron";
constexpr static char esPythonTurtleBrown[] = "Brown color";
constexpr static char dePythonTurtleBrown[] = "Brown color";
constexpr static char ptPythonTurtleBrown[] = "Brown color";
constexpr static char enPythonTurtleCircle[] = "Circle of radius r pixels";
constexpr static char frPythonTurtleCircle[] = "Cercle de rayon r pixels";
constexpr static char esPythonTurtleCircle[] = "Circle of radius r pixels";
constexpr static char dePythonTurtleCircle[] = "Circle of radius r pixels";
constexpr static char ptPythonTurtleCircle[] = "Circle of radius r pixels";
constexpr static char enPythonTurtleColor[] = "Set the pen color";
constexpr static char frPythonTurtleColor[] = "Modifie la couleur du tracé";
constexpr static char esPythonTurtleColor[] = "Set the pen color";
constexpr static char dePythonTurtleColor[] = "Set the pen color";
constexpr static char ptPythonTurtleColor[] = "Set the pen color";
constexpr static char enPythonTurtleForward[] = "Move forward by x pixels";
constexpr static char frPythonTurtleForward[] = "Avance de x pixels";
constexpr static char esPythonTurtleForward[] = "Move forward by x pixels";
constexpr static char dePythonTurtleForward[] = "Move forward by x pixels";
constexpr static char ptPythonTurtleForward[] = "Move forward by x pixels";
constexpr static char enPythonTurtleFunction[] = "turtle module function prefix";
constexpr static char frPythonTurtleFunction[] = "Préfixe fonction du module turtle";
constexpr static char esPythonTurtleFunction[] = "turtle module function prefix";
constexpr static char dePythonTurtleFunction[] = "turtle module function prefix";
constexpr static char ptPythonTurtleFunction[] = "turtle module function prefix";
constexpr static char enPythonTurtleGoto[] = "Move to (x,y) coordinates";
constexpr static char frPythonTurtleGoto[] = "Va au point de coordonnées (x,y)";
constexpr static char esPythonTurtleGoto[] = "Move to (x,y) coordinates";
constexpr static char dePythonTurtleGoto[] = "Move to (x,y) coordinates";
constexpr static char ptPythonTurtleGoto[] = "Move to (x,y) coordinates";
constexpr static char enPythonTurtleGreen[] = "Green color";
constexpr static char frPythonTurtleGreen[] = "Couleur verte";
constexpr static char esPythonTurtleGreen[] = "Green color";
constexpr static char dePythonTurtleGreen[] = "Green color";
constexpr static char ptPythonTurtleGreen[] = "Green color";
constexpr static char enPythonTurtleGrey[] = "Grey color";
constexpr static char frPythonTurtleGrey[] = "Couleur grise";
constexpr static char esPythonTurtleGrey[] = "Grey color";
constexpr static char dePythonTurtleGrey[] = "Grey color";
constexpr static char ptPythonTurtleGrey[] = "Grey color";
constexpr static char enPythonTurtleHeading[] = "Return the current heading";
constexpr static char frPythonTurtleHeading[] = "Renvoie l'orientation actuelle";
constexpr static char esPythonTurtleHeading[] = "Return the current heading";
constexpr static char dePythonTurtleHeading[] = "Return the current heading";
constexpr static char ptPythonTurtleHeading[] = "Return the current heading";
constexpr static char enPythonTurtleHideturtle[] = "Hide the turtle";
constexpr static char frPythonTurtleHideturtle[] = "Masque la tortue";
constexpr static char esPythonTurtleHideturtle[] = "Hide the turtle";
constexpr static char dePythonTurtleHideturtle[] = "Hide the turtle";
constexpr static char ptPythonTurtleHideturtle[] = "Hide the turtle";
constexpr static char enPythonTurtleIsdown[] = "Return True if the pen is down";
constexpr static char frPythonTurtleIsdown[] = "True si le crayon est abaissé";
constexpr static char esPythonTurtleIsdown[] = "Return True if the pen is down";
constexpr static char dePythonTurtleIsdown[] = "Return True if the pen is down";
constexpr static char ptPythonTurtleIsdown[] = "Return True if the pen is down";
constexpr static char enPythonTurtleLeft[] = "Turn left by a degrees";
constexpr static char frPythonTurtleLeft[] = "Pivote de a degrés vers la gauche";
constexpr static char esPythonTurtleLeft[] = "Turn left by a degrees";
constexpr static char dePythonTurtleLeft[] = "Turn left by a degrees";
constexpr static char ptPythonTurtleLeft[] = "Turn left by a degrees";
constexpr static char enPythonTurtleOrange[] = "Orange color";
constexpr static char frPythonTurtleOrange[] = "Couleur orange";
constexpr static char esPythonTurtleOrange[] = "Orange color";
constexpr static char dePythonTurtleOrange[] = "Orange color";
constexpr static char ptPythonTurtleOrange[] = "Orange color";
constexpr static char enPythonTurtlePendown[] = "Pull the pen down";
constexpr static char frPythonTurtlePendown[] = "Abaisse le crayon";
constexpr static char esPythonTurtlePendown[] = "Pull the pen down";
constexpr static char dePythonTurtlePendown[] = "Pull the pen down";
constexpr static char ptPythonTurtlePendown[] = "Pull the pen down";
constexpr static char enPythonTurtlePensize[] = "Set the line thickness to x pixels";
constexpr static char frPythonTurtlePensize[] = "Taille du tracé en pixels";
constexpr static char esPythonTurtlePensize[] = "Set the line thickness to x pixels";
constexpr static char dePythonTurtlePensize[] = "Set the line thickness to x pixels";
constexpr static char ptPythonTurtlePensize[] = "Set the line thickness to x pixels";
constexpr static char enPythonTurtlePenup[] = "Pull the pen up";
constexpr static char frPythonTurtlePenup[] = "Relève le crayon";
constexpr static char esPythonTurtlePenup[] = "Pull the pen up";
constexpr static char dePythonTurtlePenup[] = "Pull the pen up";
constexpr static char ptPythonTurtlePenup[] = "Pull the pen up";
constexpr static char enPythonTurtlePink[] = "Pink color";
constexpr static char frPythonTurtlePink[] = "Couleur rose";
constexpr static char esPythonTurtlePink[] = "Pink color";
constexpr static char dePythonTurtlePink[] = "Pink color";
constexpr static char ptPythonTurtlePink[] = "Pink color";
constexpr static char enPythonTurtlePosition[] = "Return the current (x,y) location";
constexpr static char frPythonTurtlePosition[] = "Renvoie la position (x,y) actuelle";
constexpr static char esPythonTurtlePosition[] = "Return the current (x,y) location";
constexpr static char dePythonTurtlePosition[] = "Return the current (x,y) location";
constexpr static char ptPythonTurtlePosition[] = "Return the current (x,y) location";
constexpr static char enPythonTurtlePurple[] = "Purple color";
constexpr static char frPythonTurtlePurple[] = "Couleur violette";
constexpr static char esPythonTurtlePurple[] = "Purple color";
constexpr static char dePythonTurtlePurple[] = "Purple color";
constexpr static char ptPythonTurtlePurple[] = "Purple color";
constexpr static char enPythonTurtleRed[] = "Red color";
constexpr static char frPythonTurtleRed[] = "Couleur rouge";
constexpr static char esPythonTurtleRed[] = "Red color";
constexpr static char dePythonTurtleRed[] = "Red color";
constexpr static char ptPythonTurtleRed[] = "Red color";
constexpr static char enPythonTurtleReset[] = "Reset the drawing";
constexpr static char frPythonTurtleReset[] = "Réinitialise le dessin";
constexpr static char esPythonTurtleReset[] = "Reset the drawing";
constexpr static char dePythonTurtleReset[] = "Reset the drawing";
constexpr static char ptPythonTurtleReset[] = "Reset the drawing";
constexpr static char enPythonTurtleRight[] = "Turn right by a degrees";
constexpr static char frPythonTurtleRight[] = "Pivote de a degrés vers la droite";
constexpr static char esPythonTurtleRight[] = "Turn right by a degrees";
constexpr static char dePythonTurtleRight[] = "Turn right by a degrees";
constexpr static char ptPythonTurtleRight[] = "Turn right by a degrees";
constexpr static char enPythonTurtleSetheading[] = "Set the orientation to a degrees";
constexpr static char frPythonTurtleSetheading[] = "Met une orientation de a degrés";
constexpr static char esPythonTurtleSetheading[] = "Set the orientation to a degrees";
constexpr static char dePythonTurtleSetheading[] = "Set the orientation to a degrees";
constexpr static char ptPythonTurtleSetheading[] = "Set the orientation to a degrees";
constexpr static char enPythonTurtleSetposition[] = "Positionne la tortue";
constexpr static char frPythonTurtleSetposition[] = "Positionne la tortue";
constexpr static char esPythonTurtleSetposition[] = "Positionne la tortue";
constexpr static char dePythonTurtleSetposition[] = "Positionne la tortue";
constexpr static char ptPythonTurtleSetposition[] = "Positionne la tortue";
constexpr static char enPythonTurtleShowturtle[] = "Show the turtle";
constexpr static char frPythonTurtleShowturtle[] = "Affiche la tortue";
constexpr static char esPythonTurtleShowturtle[] = "Show the turtle";
constexpr static char dePythonTurtleShowturtle[] = "Show the turtle";
constexpr static char ptPythonTurtleShowturtle[] = "Show the turtle";
constexpr static char enPythonTurtleSpeed[] = "Drawing speed between 0 and 10";
constexpr static char frPythonTurtleSpeed[] = "Vitesse du tracé entre 0 et 10";
constexpr static char esPythonTurtleSpeed[] = "Drawing speed between 0 and 10";
constexpr static char dePythonTurtleSpeed[] = "Drawing speed between 0 and 10";
constexpr static char ptPythonTurtleSpeed[] = "Drawing speed between 0 and 10";
constexpr static char enPythonTurtleWhite[] = "White color";
constexpr static char frPythonTurtleWhite[] = "Couleur blanche";
constexpr static char esPythonTurtleWhite[] = "White color";
constexpr static char dePythonTurtleWhite[] = "White color";
constexpr static char ptPythonTurtleWhite[] = "White color";
constexpr static char enPythonTurtleYellow[] = "Yellow color";
constexpr static char frPythonTurtleYellow[] = "Couleur jaune";
constexpr static char esPythonTurtleYellow[] = "Yellow color";
constexpr static char dePythonTurtleYellow[] = "Yellow color";
constexpr static char ptPythonTurtleYellow[] = "Yellow color";
constexpr static char enPythonUniform[] = "Floating point number in [a,b]";
constexpr static char frPythonUniform[] = "Nombre décimal dans [a,b]";
constexpr static char esPythonUniform[] = "Floating point number in [a,b]";
constexpr static char dePythonUniform[] = "Floating point number in [a,b]";
constexpr static char ptPythonUniform[] = "Floating point number in [a,b]";
constexpr static char enPythonVerticalBar[] = "Bitwise or";
constexpr static char frPythonVerticalBar[] = "Ou logique";
constexpr static char esPythonVerticalBar[] = "Bitwise or";
constexpr static char dePythonVerticalBar[] = "Bitweise oder";
constexpr static char ptPythonVerticalBar[] = "Bitwise or";
constexpr static char enQuadratic[] = "Quadratic";
constexpr static char frQuadratic[] = "Quadratique";
constexpr static char esQuadratic[] = "Cuadrática";
constexpr static char deQuadratic[] = "Quadratische";
constexpr static char ptQuadratic[] = "Quadrática";
constexpr static char enQuartic[] = "Quartic";
constexpr static char frQuartic[] = "Quartique";
constexpr static char esQuartic[] = "Cuártica";
constexpr static char deQuartic[] = "Biquadratische";
constexpr static char ptQuartic[] = "Quarto grau";
constexpr static char enQuotient[] = "Quotient division p by q";
constexpr static char frQuotient[] = "Quotient division p par q";
constexpr static char esQuotient[] = "Cociente división p por q";
constexpr static char deQuotient[] = "Ganzzahlquotient";
constexpr static char ptQuotient[] = "Quociente";
constexpr static char enRad[] = "rad";
constexpr static char frRad[] = "rad";
constexpr static char esRad[] = "rad";
constexpr static char deRad[] = "rad";
constexpr static char ptRad[] = "rad";
constexpr static char enRadian[] = "Radians ";
constexpr static char frRadian[] = "Radians ";
constexpr static char esRadian[] = "Radianes ";
constexpr static char deRadian[] = "Bogenmass ";
constexpr static char ptRadian[] = "Radianos ";
constexpr static char enRandomAndApproximation[] = "Random and approximation";
constexpr static char frRandomAndApproximation[] = "Aléatoire et approximation";
constexpr static char esRandomAndApproximation[] = "Aleatorio y aproximación";
constexpr static char deRandomAndApproximation[] = "Zufall und Naeherung";
constexpr static char ptRandomAndApproximation[] = "Aleatório e aproximação";
constexpr static char enRandomFloat[] = "Floating point number in [0,1[";
constexpr static char frRandomFloat[] = "Nombre décimal dans [0,1[";
constexpr static char esRandomFloat[] = "Número decimal en [0,1[";
constexpr static char deRandomFloat[] = "Dezimalzahl in [0,1]";
constexpr static char ptRandomFloat[] = "Número decimal em [0,1[";
constexpr static char enRandomInteger[] = "Random integer in [a,b]";
constexpr static char frRandomInteger[] = "Entier aléatoire dans [a,b]";
constexpr static char esRandomInteger[] = "Entero aleatorio en [a,b]";
constexpr static char deRandomInteger[] = "Zufaellige ganze Zahl in [a,b]";
constexpr static char ptRandomInteger[] = "Inteiro aleatório em [a,b]";
constexpr static char enRange[] = "Range";
constexpr static char frRange[] = "Etendue";
constexpr static char esRange[] = "Rango";
constexpr static char deRange[] = "Spannweite";
constexpr static char ptRange[] = "Amplitude";
constexpr static char enReal[] = "Real ";
constexpr static char frReal[] = "Réel ";
constexpr static char esReal[] = "Real ";
constexpr static char deReal[] = "Reel ";
constexpr static char ptReal[] = "Real ";
constexpr static char enRealPart[] = "Real part";
constexpr static char frRealPart[] = "Partie réelle";
constexpr static char esRealPart[] = "Parte real";
constexpr static char deRealPart[] = "Realteil";
constexpr static char ptRealPart[] = "Parte real";
constexpr static char enRectangleWidth[] = "Bin width";
constexpr static char frRectangleWidth[] = "Largeur des rectangles";
constexpr static char esRectangleWidth[] = "Ancho del rectangulo";
constexpr static char deRectangleWidth[] = "Breite der Rechtecke";
constexpr static char ptRectangleWidth[] = "Largura dos retângulos";
constexpr static char enReg[] = "reg";
constexpr static char frReg[] = "reg";
constexpr static char esReg[] = "reg";
constexpr static char deReg[] = "reg";
constexpr static char ptReg[] = "reg";
constexpr static char enRegression[] = "Regression";
constexpr static char frRegression[] = "Régression";
constexpr static char esRegression[] = "Regresión";
constexpr static char deRegression[] = "Regression";
constexpr static char ptRegression[] = "Regressão";
constexpr static char enRegressionApp[] = "Regression";
constexpr static char frRegressionApp[] = "Régressions";
constexpr static char esRegressionApp[] = "Regresión";
constexpr static char deRegressionApp[] = "Regression";
constexpr static char ptRegressionApp[] = "Regressão";
constexpr static char enRegressionAppCapital[] = "REGRESSION";
constexpr static char frRegressionAppCapital[] = "REGRESSIONS";
constexpr static char esRegressionAppCapital[] = "REGRESION";
constexpr static char deRegressionAppCapital[] = "REGRESSION";
constexpr static char ptRegressionAppCapital[] = "REGRESSAO";
constexpr static char enRegressionCurve[] = "Regression curve";
constexpr static char frRegressionCurve[] = "Courbe de régression";
constexpr static char esRegressionCurve[] = "Curva de regresión";
constexpr static char deRegressionCurve[] = "Regressionskurve";
constexpr static char ptRegressionCurve[] = "Curva de regressão";
constexpr static char enRemainder[] = "Remainder division p by q";
constexpr static char frRemainder[] = "Reste division p par q";
constexpr static char esRemainder[] = "Resto división p por q";
constexpr static char deRemainder[] = "Rest";
constexpr static char ptRemainder[] = "Resto da divisao inteira";
constexpr static char enRename[] = "Rename";
constexpr static char frRename[] = "Renommer";
constexpr static char esRename[] = "Renombrar";
constexpr static char deRename[] = "Umbenennen";
constexpr static char ptRename[] = "Renomear";
constexpr static char enRepetitionNumber[] = "n: Number of trials";
constexpr static char frRepetitionNumber[] = "n : Nombre de répétitions";
constexpr static char esRepetitionNumber[] = "n : Número de ensayos ";
constexpr static char deRepetitionNumber[] = "n: Anzahl der Versuche";
constexpr static char ptRepetitionNumber[] = "n : Número de ensaios";
constexpr static char enRequireEquation[] = "The input must be an equation";
constexpr static char frRequireEquation[] = "L'entrée doit être une équation";
constexpr static char esRequireEquation[] = "La entrada debe ser una ecuación";
constexpr static char deRequireEquation[] = "Die Eingabe muss eine Gleichung sein";
constexpr static char ptRequireEquation[] = "A entrada deve ser uma equação";
constexpr static char enReservedName[] = "Reserved name";
constexpr static char frReservedName[] = "Nom réservé";
constexpr static char esReservedName[] = "Nombre reservado";
constexpr static char deReservedName[] = "Reserviertes Wort";
constexpr static char ptReservedName[] = "Nome reservado";
constexpr static char enResolveEquation[] = "Solve the equation";
constexpr static char frResolveEquation[] = "Résoudre l'équation";
constexpr static char esResolveEquation[] = "Resolver la ecuación";
constexpr static char deResolveEquation[] = "Loesen der Gleichung";
constexpr static char ptResolveEquation[] = "Resolver a equação";
constexpr static char enResolveSystem[] = "Solve the system";
constexpr static char frResolveSystem[] = "Résoudre le système";
constexpr static char esResolveSystem[] = "Resolver el sistema";
constexpr static char deResolveSystem[] = "Loesen des Gleichungssystems";
constexpr static char ptResolveSystem[] = "Resolver o sistema";
constexpr static char enRoundAbscissa[] = "Integer";
constexpr static char frRoundAbscissa[] = "Abscisses entières";
constexpr static char esRoundAbscissa[] = "Abscisas enteras";
constexpr static char deRoundAbscissa[] = "Ganzzahl";
constexpr static char ptRoundAbscissa[] = "Inteiro";
constexpr static char enRounding[] = "Rounding to n digits";
constexpr static char frRounding[] = "Arrondi n chiffres";
constexpr static char esRounding[] = "Redondeo n digitos";
constexpr static char deRounding[] = "Runden";
constexpr static char ptRounding[] = "Arredondar";
constexpr static char enSampleStandardDeviationS[] = "Sample std deviation s";
constexpr static char frSampleStandardDeviationS[] = "Ecart type échantillon";
constexpr static char esSampleStandardDeviationS[] = "Desviación típica s";
constexpr static char deSampleStandardDeviationS[] = "Standardabweichung s";
constexpr static char ptSampleStandardDeviationS[] = "Desvio padrão amostral s";
constexpr static char enSci[] = "sci/";
constexpr static char frSci[] = "sci/";
constexpr static char esSci[] = "sci/";
constexpr static char deSci[] = "sci/";
constexpr static char ptSci[] = "sci/";
constexpr static char enScientific[] = "Scientific ";
constexpr static char frScientific[] = "Scientifique ";
constexpr static char esScientific[] = "Científico ";
constexpr static char deScientific[] = "Wissenschaftlich ";
constexpr static char ptScientific[] = "Científico ";
constexpr static char enScriptOptions[] = "Script options";
constexpr static char frScriptOptions[] = "Options de script";
constexpr static char esScriptOptions[] = "Opciones del archivo";
constexpr static char deScriptOptions[] = "Skriptoptionen";
constexpr static char ptScriptOptions[] = "Opções de script";
constexpr static char enSearchInverval[] = "Search interval";
constexpr static char frSearchInverval[] = "Intervalle de recherche";
constexpr static char esSearchInverval[] = "Intervalo de búsqueda";
constexpr static char deSearchInverval[] = "Loesungssuche Intervall";
constexpr static char ptSearchInverval[] = "Intervalo de busca";
constexpr static char enSelectFirstTerm[] = "Select First Term ";
constexpr static char frSelectFirstTerm[] = "Sélectionner le premier terme ";
constexpr static char esSelectFirstTerm[] = "Seleccionar el primer término ";
constexpr static char deSelectFirstTerm[] = "Erster Term ";
constexpr static char ptSelectFirstTerm[] = "Selecionar primeiro termo ";
constexpr static char enSelectLastTerm[] = "Select last term ";
constexpr static char frSelectLastTerm[] = "Sélectionner le dernier terme ";
constexpr static char esSelectLastTerm[] = "Seleccionar el último término ";
constexpr static char deSelectLastTerm[] = "Letzter Term ";
constexpr static char ptSelectLastTerm[] = "Selecionar último termo ";
constexpr static char enSelectLowerBound[] = "Select lower bound";
constexpr static char frSelectLowerBound[] = "Selectionner la borne inférieure";
constexpr static char esSelectLowerBound[] = "Seleccionar el límite inferior";
constexpr static char deSelectLowerBound[] = "Untere Integrationsgrenze";
constexpr static char ptSelectLowerBound[] = "Selecionar limite superior";
constexpr static char enSelectUpperBound[] = "Select upper bound";
constexpr static char frSelectUpperBound[] = "Selectionner la borne supérieure";
constexpr static char esSelectUpperBound[] = "Seleccionar el límite superior";
constexpr static char deSelectUpperBound[] = "Obere Integrationsgrenze";
constexpr static char ptSelectUpperBound[] = "Selecionar limite inferior";
constexpr static char enSequenceApp[] = "Sequences";
constexpr static char frSequenceApp[] = "Suites";
constexpr static char esSequenceApp[] = "Sucesión";
constexpr static char deSequenceApp[] = "Folge";
constexpr static char ptSequenceApp[] = "Sequência";
constexpr static char enSequenceAppCapital[] = "SEQUENCES";
constexpr static char frSequenceAppCapital[] = "SUITES";
constexpr static char esSequenceAppCapital[] = "SUCESION";
constexpr static char deSequenceAppCapital[] = "FOLGE";
constexpr static char ptSequenceAppCapital[] = "SEQUENCIA";
constexpr static char enSequenceColor[] = "Sequence color";
constexpr static char frSequenceColor[] = "Couleur de la suite";
constexpr static char esSequenceColor[] = "Color de la sucesión";
constexpr static char deSequenceColor[] = "Farbe der Folge";
constexpr static char ptSequenceColor[] = "Cor da sequência";
constexpr static char enSequenceOptions[] = "Sequence options";
constexpr static char frSequenceOptions[] = "Options de la suite";
constexpr static char esSequenceOptions[] = "Opciones de la sucesión";
constexpr static char deSequenceOptions[] = "Optionen der Folge";
constexpr static char ptSequenceOptions[] = "Opções de sequência";
constexpr static char enSequenceTab[] = "Sequences";
constexpr static char frSequenceTab[] = "Suites";
constexpr static char esSequenceTab[] = "Sucesiones";
constexpr static char deSequenceTab[] = "Folgen";
constexpr static char ptSequenceTab[] = "Sequências";
constexpr static char enSequenceType[] = "Sequence type";
constexpr static char frSequenceType[] = "Type de suite";
constexpr static char esSequenceType[] = "Tipo de sucesión";
constexpr static char deSequenceType[] = "Bildungsgesetz der Folge";
constexpr static char ptSequenceType[] = "Tipo de sequência";
constexpr static char enSerialNumber[] = "Serial number";
constexpr static char frSerialNumber[] = "Numéro serie";
constexpr static char esSerialNumber[] = "Número serie";
constexpr static char deSerialNumber[] = "Seriennummer";
constexpr static char ptSerialNumber[] = "Número serie";
constexpr static char enSettingsApp[] = "Settings";
constexpr static char frSettingsApp[] = "Paramètres";
constexpr static char esSettingsApp[] = "Configuración";
constexpr static char deSettingsApp[] = "Einstellungen";
constexpr static char ptSettingsApp[] = "Configuração";
constexpr static char enSettingsAppCapital[] = "SETTINGS";
constexpr static char frSettingsAppCapital[] = "PARAMETRES";
constexpr static char esSettingsAppCapital[] = "CONFIGURACION";
constexpr static char deSettingsAppCapital[] = "EINSTELLUNGEN";
constexpr static char ptSettingsAppCapital[] = "CONFIGURACAO";
constexpr static char enSignificantFigures[] = "Significant figures ";
constexpr static char frSignificantFigures[] = "Chiffres significatifs ";
constexpr static char esSignificantFigures[] = "Cifras significativas ";
constexpr static char deSignificantFigures[] = "Signifikante Stellen ";
constexpr static char ptSignificantFigures[] = "Algarismo significativo ";
constexpr static char enSingleRecurrence[] = "Recursive first order";
constexpr static char frSingleRecurrence[] = "Récurrente d'ordre 1";
constexpr static char esSingleRecurrence[] = "Recurrencia de orden uno";
constexpr static char deSingleRecurrence[] = "Rekursion 1. Ordnung";
constexpr static char ptSingleRecurrence[] = "Recorrência de Primeira Ordem";
constexpr static char enSize[] = " Size";
constexpr static char frSize[] = " Effectif";
constexpr static char esSize[] = " Frecuencia";
constexpr static char deSize[] = " Haeufigkeit";
constexpr static char ptSize[] = " Frequência";
constexpr static char enSizes1[] = "Sizes N1";
constexpr static char frSizes1[] = "Effectifs N1";
constexpr static char esSizes1[] = "Frecuencias N1";
constexpr static char deSizes1[] = "Haeufigkeiten N1";
constexpr static char ptSizes1[] = "Frequências N1";
constexpr static char enSizes2[] = "Sizes N2";
constexpr static char frSizes2[] = "Effectifs N2";
constexpr static char esSizes2[] = "Frecuencias N2";
constexpr static char deSizes2[] = "Haeufigkeiten N2";
constexpr static char ptSizes2[] = "Frequências N2";
constexpr static char enSizes3[] = "Sizes N3";
constexpr static char frSizes3[] = "Effectifs N3";
constexpr static char esSizes3[] = "Frecuencias N3";
constexpr static char deSizes3[] = "Haeufigkeiten N3";
constexpr static char ptSizes3[] = "Frequências N3";
constexpr static char enSkip[] = "Skip";
constexpr static char frSkip[] = "Passer";
constexpr static char esSkip[] = "Saltar";
constexpr static char deSkip[] = "Ueberspringen";
constexpr static char ptSkip[] = "Pular";
constexpr static char enSoftwareVersion[] = "Software version";
constexpr static char frSoftwareVersion[] = "Version du logiciel";
constexpr static char esSoftwareVersion[] = "Versión de software";
constexpr static char deSoftwareVersion[] = "Softwareversion";
constexpr static char ptSoftwareVersion[] = "Versão do software";
constexpr static char enSolution[] = "Solution";
constexpr static char frSolution[] = "Solution";
constexpr static char esSolution[] = "Solución";
constexpr static char deSolution[] = "Loesung";
constexpr static char ptSolution[] = "Solução";
constexpr static char enSolverApp[] = "Equations";
constexpr static char frSolverApp[] = "Equations";
constexpr static char esSolverApp[] = "Ecuaciones";
constexpr static char deSolverApp[] = "Gleichungen";
constexpr static char ptSolverApp[] = "Equações";
constexpr static char enSolverAppCapital[] = "EQUATIONS";
constexpr static char frSolverAppCapital[] = "EQUATIONS";
constexpr static char esSolverAppCapital[] = "ECUACIONES";
constexpr static char deSolverAppCapital[] = "GLEICHUNGEN";
constexpr static char ptSolverAppCapital[] = "EQUACOES";
constexpr static char enSort[] = "Sort ascending ";
constexpr static char frSort[] = "Tri croissant";
constexpr static char esSort[] = "Clasificación ascendente";
constexpr static char deSort[] = "Sortieren aufsteigend";
constexpr static char ptSort[] = "Ordem crescente";
constexpr static char enSquareSum[] = "Sum of squares";
constexpr static char frSquareSum[] = "Somme des carrés";
constexpr static char esSquareSum[] = "Suma cuadrados";
constexpr static char deSquareSum[] = "Quadratsumme";
constexpr static char ptSquareSum[] = "Soma dos quadrados";
constexpr static char enStandardDeviation[] = "Standard deviation";
constexpr static char frStandardDeviation[] = "Ecart type";
constexpr static char esStandardDeviation[] = "Desviación típica";
constexpr static char deStandardDeviation[] = "Standardabweichung";
constexpr static char ptStandardDeviation[] = "Desvio padrão";
constexpr static char enStandardDeviationSigma[] = "Standard deviation σ";
constexpr static char frStandardDeviationSigma[] = "Ecart type";
constexpr static char esStandardDeviationSigma[] = "Desviación típica σ";
constexpr static char deStandardDeviationSigma[] = "Standardabweichung σ";
constexpr static char ptStandardDeviationSigma[] = "Desvio padrão σ";
constexpr static char enStatTab[] = "Stats";
constexpr static char frStatTab[] = "Stats";
constexpr static char esStatTab[] = "Medidas";
constexpr static char deStatTab[] = "Stats";
constexpr static char ptStatTab[] = "Estat";
constexpr static char enStatsApp[] = "Statistics";
constexpr static char frStatsApp[] = "Statistiques";
constexpr static char esStatsApp[] = "Estadística";
constexpr static char deStatsApp[] = "Statistik";
constexpr static char ptStatsApp[] = "Estatística";
constexpr static char enStatsAppCapital[] = "STATISTICS";
constexpr static char frStatsAppCapital[] = "STATISTIQUES";
constexpr static char esStatsAppCapital[] = "ESTADISTICA";
constexpr static char deStatsAppCapital[] = "STATISTIK";
constexpr static char ptStatsAppCapital[] = "ESTATISTICA";
constexpr static char enStep[] = "Step";
constexpr static char frStep[] = "Pas";
constexpr static char esStep[] = "Incremento";
constexpr static char deStep[] = "Schrittwert";
constexpr static char ptStep[] = "Passo";
constexpr static char enStorageMemoryFull1[] = "The memory is full.";
constexpr static char frStorageMemoryFull1[] = "La mémoire est pleine.";
constexpr static char esStorageMemoryFull1[] = "La memoria está llena.";
constexpr static char deStorageMemoryFull1[] = "Der Speicher ist voll. Löschen Sie";
constexpr static char ptStorageMemoryFull1[] = "A memoria esta chéia.";
constexpr static char enStorageMemoryFull2[] = "Erase data and try again.";
constexpr static char frStorageMemoryFull2[] = "Effacez des données et réessayez.";
constexpr static char esStorageMemoryFull2[] = "Borre datos e intente de nuevo.";
constexpr static char deStorageMemoryFull2[] = "von Daten und versuchen Sie es erneut.";
constexpr static char ptStorageMemoryFull2[] = "Apage dados e tente novamente.";
constexpr static char enStoreExpressionNotAllowed[] = "'store' is not allowed";
constexpr static char frStoreExpressionNotAllowed[] = "'store' n'est pas autorisé";
constexpr static char esStoreExpressionNotAllowed[] = "'store' no está permitido";
constexpr static char deStoreExpressionNotAllowed[] = "'store' ist verboten";
constexpr static char ptStoreExpressionNotAllowed[] = "'store' não está permitido";
constexpr static char enSuccessProbability[] = "p: Success probability";
constexpr static char frSuccessProbability[] = "p : Probabilité de succès";
constexpr static char esSuccessProbability[] = "p : Probabilidad de éxito ";
constexpr static char deSuccessProbability[] = "p: Erfolgswahrscheinlichkeit";
constexpr static char ptSuccessProbability[] = "p : Probabilidade de sucesso";
constexpr static char enSum[] = "Sum";
constexpr static char frSum[] = "Somme";
constexpr static char esSum[] = "Suma";
constexpr static char deSum[] = "Summe";
constexpr static char ptSum[] = "Somatorio";
constexpr static char enSyntaxError[] = "Syntax error";
constexpr static char frSyntaxError[] = "Attention à la syntaxe";
constexpr static char esSyntaxError[] = "Error sintáctico";
constexpr static char deSyntaxError[] = "Syntaxfehler";
constexpr static char ptSyntaxError[] = "Erro de sintaxe";
constexpr static char enTangent[] = "Tangent";
constexpr static char frTangent[] = "Tangente";
constexpr static char esTangent[] = "Tangente";
constexpr static char deTangent[] = "Tangente";
constexpr static char ptTangent[] = "Tangente";
constexpr static char enTermSum[] = "Sum of terms";
constexpr static char frTermSum[] = "Somme des termes";
constexpr static char esTermSum[] = "Suma de términos";
constexpr static char deTermSum[] = "Summe der Terme";
constexpr static char ptTermSum[] = "Soma dos termos";
constexpr static char enThirdQuartile[] = "Third quartile";
constexpr static char frThirdQuartile[] = "Troisième quartile";
constexpr static char esThirdQuartile[] = "Tercer cuartil";
constexpr static char deThirdQuartile[] = "Oberes Quartil";
constexpr static char ptThirdQuartile[] = "Quartil superior";
constexpr static char enToZoom[] = "Zoom: ";
constexpr static char frToZoom[] = "Zoomer : ";
constexpr static char esToZoom[] = "Zoom : ";
constexpr static char deToZoom[] = "Zoom: ";
constexpr static char ptToZoom[] = "Zoom : ";
constexpr static char enTooManyVariables[] = "There are too many unknowns";
constexpr static char frTooManyVariables[] = "Le nombre d'inconnues est trop grand";
constexpr static char esTooManyVariables[] = "Hay demasiadas incógnitas";
constexpr static char deTooManyVariables[] = "Es gibt zu viele Unbekannte";
constexpr static char ptTooManyVariables[] = "Existem muitas incógnitas";
constexpr static char enToolbox[] = "Toolbox";
constexpr static char frToolbox[] = "Boîte à outils";
constexpr static char esToolbox[] = "Caja de herramientas";
constexpr static char deToolbox[] = "Werkzeugkasten";
constexpr static char ptToolbox[] = "Caixa de ferramentas";
constexpr static char enTotalSize[] = "Total size";
constexpr static char frTotalSize[] = "Effectif total";
constexpr static char esTotalSize[] = "Población";
constexpr static char deTotalSize[] = "Anzahl der Elemente";
constexpr static char ptTotalSize[] = "Número de itens";
constexpr static char enTrace[] = "Trace";
constexpr static char frTrace[] = "Trace ";
constexpr static char esTrace[] = "Traza";
constexpr static char deTrace[] = "Spur";
constexpr static char ptTrace[] = "Traco";
constexpr static char enTranspose[] = "Transpose";
constexpr static char frTranspose[] = "Transposée";
constexpr static char esTranspose[] = "Transpuesta";
constexpr static char deTranspose[] = "Transponierte";
constexpr static char ptTranspose[] = "Matriz transposta";
constexpr static char enTrigonometric[] = "Trigonometrical";
constexpr static char frTrigonometric[] = "Trigonométrique";
constexpr static char esTrigonometric[] = "Trigonométrico";
constexpr static char deTrigonometric[] = "Trigonometrisch";
constexpr static char ptTrigonometric[] = "Trigonométrico";
constexpr static char enTrigonometrical[] = "Trigonometric";
constexpr static char frTrigonometrical[] = "Trigonométrique";
constexpr static char esTrigonometrical[] = "Trigonométrica";
constexpr static char deTrigonometrical[] = "Trigonometrische";
constexpr static char ptTrigonometrical[] = "Trigonométrica";
constexpr static char enUSBConnected[] = "THE CALCULATOR IS CONNECTED";
constexpr static char frUSBConnected[] = "LA CALCULATRICE EST CONNECTEE";
constexpr static char esUSBConnected[] = "CALCULADORA CONECTADA";
constexpr static char deUSBConnected[] = "DER RECHNER IST ANGESCHLOSSEN";
constexpr static char ptUSBConnected[] = "A CALCULADORA ESTA CONECTADA";
constexpr static char enUndefinedEquation[] = "Undefined equation";
constexpr static char frUndefinedEquation[] = "Une équation est indéfinie";
constexpr static char esUndefinedEquation[] = "Una ecuación es indefinida";
constexpr static char deUndefinedEquation[] = "Nicht definierte Gleichung";
constexpr static char ptUndefinedEquation[] = "Uma equação é indefinida";
constexpr static char enUndefinedValue[] = "Undefined value";
constexpr static char frUndefinedValue[] = "Valeur non définie";
constexpr static char esUndefinedValue[] = "Valor indefinido";
constexpr static char deUndefinedValue[] = "Nicht definierter Wert";
constexpr static char ptUndefinedValue[] = "Valor indefinido";
constexpr static char enUniformLaw[] = "Uniform distribution";
constexpr static char frUniformLaw[] = "Loi uniforme";
constexpr static char esUniformLaw[] = "Distribución uniforme";
constexpr static char deUniformLaw[] = "Uniformverteilung";
constexpr static char ptUniformLaw[] = "Distribuição uniforme";
constexpr static char enUniforme[] = "Uniform";
constexpr static char frUniforme[] = "Uniforme";
constexpr static char esUniforme[] = "Uniforme";
constexpr static char deUniforme[] = "Uniform";
constexpr static char ptUniforme[] = "Uniforme";
constexpr static char enUnrealEquation[] = "Unreal equation";
constexpr static char frUnrealEquation[] = "Une équation n'est pas réelle";
constexpr static char esUnrealEquation[] = "Una ecuación no es real";
constexpr static char deUnrealEquation[] = "Nicht reelle Gleichung";
constexpr static char ptUnrealEquation[] = "Uma equação não é real";
constexpr static char enUpdateAvailable[] = "UPDATE AVAILABLE";
constexpr static char frUpdateAvailable[] = "MISE A JOUR DISPONIBLE";
constexpr static char esUpdateAvailable[] = "ACTUALIZACION DISPONIBLE";
constexpr static char deUpdateAvailable[] = "UPDATE VERFUEGBAR";
constexpr static char ptUpdateAvailable[] = "ATUALIZACAO DISPONIVEL";
constexpr static char enUpdateMessage1[] = "There are important upgrades";
constexpr static char frUpdateMessage1[] = "Des améliorations importantes existent";
constexpr static char esUpdateMessage1[] = "Hay mejoras importantes";
constexpr static char deUpdateMessage1[] = "Wichtige Verbesserungen fuer Ihren";
constexpr static char ptUpdateMessage1[] = "Existem melhorias significativas";
constexpr static char enUpdateMessage2[] = "for your calculator.";
constexpr static char frUpdateMessage2[] = "pour votre calculatrice.";
constexpr static char esUpdateMessage2[] = "para su calculadora.";
constexpr static char deUpdateMessage2[] = "Rechner stehen zur Verfuegung.";
constexpr static char ptUpdateMessage2[] = "para a sua calculadora.";
constexpr static char enUpdateMessage3[] = "Browse our page from your computer";
constexpr static char frUpdateMessage3[] = "Connectez-vous depuis votre ordinateur";
constexpr static char esUpdateMessage3[] = "Visite nuestra página desde su ordenador";
constexpr static char deUpdateMessage3[] = "Verbinden Sie sich mit Ihrem Computer auf";
constexpr static char ptUpdateMessage3[] = "Navegue na nossa página do seu computador";
constexpr static char enUpdateMessage4[] = "www.numworks.com/update";
constexpr static char frUpdateMessage4[] = "www.numworks.com/update";
constexpr static char esUpdateMessage4[] = "www.numworks.com/update";
constexpr static char deUpdateMessage4[] = "www.numworks.com/update.";
constexpr static char ptUpdateMessage4[] = "www.numworks.com/update";
constexpr static char enUpdatePopUp[] = "Update pop-up";
constexpr static char frUpdatePopUp[] = "Rappel mise à jour";
constexpr static char esUpdatePopUp[] = "Pop-up de actualización";
constexpr static char deUpdatePopUp[] = "Erinnerung: Update";
constexpr static char ptUpdatePopUp[] = "Alertas de atualização";
constexpr static char enUseEquationModel[] = "Use an equation template";
constexpr static char frUseEquationModel[] = "Utiliser un modèle d'équation";
constexpr static char esUseEquationModel[] = "Usar un modelo de ecuación";
constexpr static char deUseEquationModel[] = "Verwenden Sie ein Gleichungsmodell";
constexpr static char ptUseEquationModel[] = "Usar um modelo de equação";
constexpr static char enValueNotReachedByFunction[] = "Value not reached by function";
constexpr static char frValueNotReachedByFunction[] = "Valeur non atteinte par la fonction";
constexpr static char esValueNotReachedByFunction[] = "No se alcanza este valor";
constexpr static char deValueNotReachedByFunction[] = "Der Wert wird von der Funktion nicht erreicht";
constexpr static char ptValueNotReachedByFunction[] = "O valor não é alcançado pela função";
constexpr static char enValueNotReachedByRegression[] = "Value not reached in this window";
constexpr static char frValueNotReachedByRegression[] = "Valeur non atteinte dans cette fenêtre";
constexpr static char esValueNotReachedByRegression[] = "Valor no alcanzado en esta ventana";
constexpr static char deValueNotReachedByRegression[] = "Wert in diesem Fenster nicht erreicht";
constexpr static char ptValueNotReachedByRegression[] = "Valor não alcançado nesta janela";
constexpr static char enValueNotReachedBySequence[] = "Value not reached by sequence";
constexpr static char frValueNotReachedBySequence[] = "Valeur non atteinte par la suite";
constexpr static char esValueNotReachedBySequence[] = "No se alcanza este valor";
constexpr static char deValueNotReachedBySequence[] = "Der Wert wird von der Folge nicht erreicht";
constexpr static char ptValueNotReachedBySequence[] = "O valor não é alcançado pela sequência";
constexpr static char enValues1[] = "Values V1";
constexpr static char frValues1[] = "Valeurs V1";
constexpr static char esValues1[] = "Valores V1";
constexpr static char deValues1[] = "Werte V1";
constexpr static char ptValues1[] = "Valores V1";
constexpr static char enValues2[] = "Values V2";
constexpr static char frValues2[] = "Valeurs V2";
constexpr static char esValues2[] = "Valores V2";
constexpr static char deValues2[] = "Werte V2";
constexpr static char ptValues2[] = "Valores V2";
constexpr static char enValues3[] = "Values V3";
constexpr static char frValues3[] = "Valeurs V3";
constexpr static char esValues3[] = "Valores V3";
constexpr static char deValues3[] = "Werte V3";
constexpr static char ptValues3[] = "Valores V3";
constexpr static char enValuesTab[] = "Table";
constexpr static char frValuesTab[] = "Tableau";
constexpr static char esValuesTab[] = "Tabla";
constexpr static char deValuesTab[] = "Tabelle";
constexpr static char ptValuesTab[] = "Tabela";
constexpr static char enVariables[] = "Variables";
constexpr static char frVariables[] = "Variables";
constexpr static char esVariables[] = "Variables";
constexpr static char deVariables[] = "Variablen";
constexpr static char ptVariables[] = "Variáveis";
constexpr static char enWarning[] = "Warning";
constexpr static char frWarning[] = "Attention";
constexpr static char esWarning[] = "Cuidado";
constexpr static char deWarning[] = "Achtung";
constexpr static char ptWarning[] = "Atenção";
constexpr static char enXEnd[] = "X end";
constexpr static char frXEnd[] = "X fin";
constexpr static char esXEnd[] = "X fin";
constexpr static char deXEnd[] = "Endwert";
constexpr static char ptXEnd[] = "X fim";
constexpr static char enXPrediction[] = "Prediction given X";
constexpr static char frXPrediction[] = "Prédiction sachant X";
constexpr static char esXPrediction[] = "Predicción dado X";
constexpr static char deXPrediction[] = "Berechne Y";
constexpr static char ptXPrediction[] = "Predição dado X";
constexpr static char enXStart[] = "X start";
constexpr static char frXStart[] = "X début";
constexpr static char esXStart[] = "X inicio";
constexpr static char deXStart[] = "Startwert";
constexpr static char ptXStart[] = "X inicio";
constexpr static char enYPrediction[] = "Prediction given Y";
constexpr static char frYPrediction[] = "Prédiction sachant Y";
constexpr static char esYPrediction[] = "Predicción dado Y";
constexpr static char deYPrediction[] = "Berechne X";
constexpr static char ptYPrediction[] = "Predição dado Y";
constexpr static char enZeros[] = "Zeros";
constexpr static char frZeros[] = "Zéros";
constexpr static char esZeros[] = "Raíces";
constexpr static char deZeros[] = "Nullstellen";
constexpr static char ptZeros[] = "Raízes";
constexpr static char enZoom[] = "Zoom";
constexpr static char frZoom[] = "Zoom";
constexpr static char esZoom[] = "Zoom";
constexpr static char deZoom[] = "Zoom";
constexpr static char ptZoom[] = "Zoom";

constexpr static const char * messages[462][5] = {
  {enAbout, frAbout, esAbout, deAbout, ptAbout, },
  {enAbsoluteValue, frAbsoluteValue, esAbsoluteValue, deAbsoluteValue, ptAbsoluteValue, },
  {enActivateDeactivate, frActivateDeactivate, esActivateDeactivate, deActivateDeactivate, ptActivateDeactivate, },
  {enActivateExamMode, frActivateExamMode, esActivateExamMode, deActivateExamMode, ptActivateExamMode, },
  {enActiveExamModeMessage1, frActiveExamModeMessage1, esActiveExamModeMessage1, deActiveExamModeMessage1, ptActiveExamModeMessage1, },
  {enActiveExamModeMessage2, frActiveExamModeMessage2, esActiveExamModeMessage2, deActiveExamModeMessage2, ptActiveExamModeMessage2, },
  {enActiveExamModeMessage3, frActiveExamModeMessage3, esActiveExamModeMessage3, deActiveExamModeMessage3, ptActiveExamModeMessage3, },
  {enAddEquation, frAddEquation, esAddEquation, deAddEquation, ptAddEquation, },
  {enAddFunction, frAddFunction, esAddFunction, deAddFunction, ptAddFunction, },
  {enAddScript, frAddScript, esAddScript, deAddScript, ptAddScript, },
  {enAddSequence, frAddSequence, esAddSequence, deAddSequence, ptAddSequence, },
  {enAgument, frAgument, esAgument, deAgument, ptAgument, },
  {enAllowedCharactersAZaz09, frAllowedCharactersAZaz09, esAllowedCharactersAZaz09, deAllowedCharactersAZaz09, ptAllowedCharactersAZaz09, },
  {enAllowedCharactersaz09, frAllowedCharactersaz09, esAllowedCharactersaz09, deAllowedCharactersaz09, ptAllowedCharactersaz09, },
  {enAngleUnit, frAngleUnit, esAngleUnit, deAngleUnit, ptAngleUnit, },
  {enApproximateSolution, frApproximateSolution, esApproximateSolution, deApproximateSolution, ptApproximateSolution, },
  {enApproximateSolutionIntervalInstruction0, frApproximateSolutionIntervalInstruction0, esApproximateSolutionIntervalInstruction0, deApproximateSolutionIntervalInstruction0, ptApproximateSolutionIntervalInstruction0, },
  {enApproximateSolutionIntervalInstruction1, frApproximateSolutionIntervalInstruction1, esApproximateSolutionIntervalInstruction1, deApproximateSolutionIntervalInstruction1, ptApproximateSolutionIntervalInstruction1, },
  {enApps, frApps, esApps, deApps, ptApps, },
  {enAppsCapital, frAppsCapital, esAppsCapital, deAppsCapital, ptAppsCapital, },
  {enArithmetic, frArithmetic, esArithmetic, deArithmetic, ptArithmetic, },
  {enAutoImportScript, frAutoImportScript, esAutoImportScript, deAutoImportScript, ptAutoImportScript, },
  {enAxis, frAxis, esAxis, deAxis, ptAxis, },
  {enBarStart, frBarStart, esBarStart, deBarStart, ptBarStart, },
  {enBasedLogarithm, frBasedLogarithm, esBasedLogarithm, deBasedLogarithm, ptBasedLogarithm, },
  {enBetaPopUp, frBetaPopUp, esBetaPopUp, deBetaPopUp, ptBetaPopUp, },
  {enBetaVersion, frBetaVersion, esBetaVersion, deBetaVersion, ptBetaVersion, },
  {enBetaVersionMessage1, frBetaVersionMessage1, esBetaVersionMessage1, deBetaVersionMessage1, ptBetaVersionMessage1, },
  {enBetaVersionMessage2, frBetaVersionMessage2, esBetaVersionMessage2, deBetaVersionMessage2, ptBetaVersionMessage2, },
  {enBetaVersionMessage3, frBetaVersionMessage3, esBetaVersionMessage3, deBetaVersionMessage3, ptBetaVersionMessage3, },
  {enBetaVersionMessage4, frBetaVersionMessage4, esBetaVersionMessage4, deBetaVersionMessage4, ptBetaVersionMessage4, },
  {enBetaVersionMessage5, frBetaVersionMessage5, esBetaVersionMessage5, deBetaVersionMessage5, ptBetaVersionMessage5, },
  {enBetaVersionMessage6, frBetaVersionMessage6, esBetaVersionMessage6, deBetaVersionMessage6, ptBetaVersionMessage6, },
  {enBinomial, frBinomial, esBinomial, deBinomial, ptBinomial, },
  {enBinomialLaw, frBinomialLaw, esBinomialLaw, deBinomialLaw, ptBinomialLaw, },
  {enBoxTab, frBoxTab, esBoxTab, deBoxTab, ptBoxTab, },
  {enBrightness, frBrightness, esBrightness, deBrightness, ptBrightness, },
  {enCalculApp, frCalculApp, esCalculApp, deCalculApp, ptCalculApp, },
  {enCalculAppCapital, frCalculAppCapital, esCalculAppCapital, deCalculAppCapital, ptCalculAppCapital, },
  {enCalculation, frCalculation, esCalculation, deCalculation, ptCalculation, },
  {enCancel, frCancel, esCancel, deCancel, ptCancel, },
  {enCartesian, frCartesian, esCartesian, deCartesian, ptCartesian, },
  {enCatalog, frCatalog, esCatalog, deCatalog, ptCatalog, },
  {enCeiling, frCeiling, esCeiling, deCeiling, ptCeiling, },
  {enChooseLaw, frChooseLaw, esChooseLaw, deChooseLaw, ptChooseLaw, },
  {enChooseParameters, frChooseParameters, esChooseParameters, deChooseParameters, ptChooseParameters, },
  {enChooseSequenceType, frChooseSequenceType, esChooseSequenceType, deChooseSequenceType, ptChooseSequenceType, },
  {enClearColumn, frClearColumn, esClearColumn, deClearColumn, ptClearColumn, },
  {enColumnOptions, frColumnOptions, esColumnOptions, deColumnOptions, ptColumnOptions, },
  {enCombination, frCombination, esCombination, deCombination, ptCombination, },
  {enComplexAbsoluteValue, frComplexAbsoluteValue, esComplexAbsoluteValue, deComplexAbsoluteValue, ptComplexAbsoluteValue, },
  {enComplexFormat, frComplexFormat, esComplexFormat, deComplexFormat, ptComplexFormat, },
  {enComplexNumber, frComplexNumber, esComplexNumber, deComplexNumber, ptComplexNumber, },
  {enCompute, frCompute, esCompute, deCompute, ptCompute, },
  {enComputeProbability, frComputeProbability, esComputeProbability, deComputeProbability, ptComputeProbability, },
  {enConfidence, frConfidence, esConfidence, deConfidence, ptConfidence, },
  {enConjugate, frConjugate, esConjugate, deConjugate, ptConjugate, },
  {enConnectedMessage1, frConnectedMessage1, esConnectedMessage1, deConnectedMessage1, ptConnectedMessage1, },
  {enConnectedMessage2, frConnectedMessage2, esConnectedMessage2, deConnectedMessage2, ptConnectedMessage2, },
  {enConnectedMessage3, frConnectedMessage3, esConnectedMessage3, deConnectedMessage3, ptConnectedMessage3, },
  {enConnectedMessage4, frConnectedMessage4, esConnectedMessage4, deConnectedMessage4, ptConnectedMessage4, },
  {enConnectedMessage5, frConnectedMessage5, esConnectedMessage5, deConnectedMessage5, ptConnectedMessage5, },
  {enConnectedMessage6, frConnectedMessage6, esConnectedMessage6, deConnectedMessage6, ptConnectedMessage6, },
  {enConsole, frConsole, esConsole, deConsole, ptConsole, },
  {enCopyColumnInList, frCopyColumnInList, esCopyColumnInList, deCopyColumnInList, ptCopyColumnInList, },
  {enCovariance, frCovariance, esCovariance, deCovariance, ptCovariance, },
  {enCubic, frCubic, esCubic, deCubic, ptCubic, },
  {enDataNotSuitable, frDataNotSuitable, esDataNotSuitable, deDataNotSuitable, ptDataNotSuitable, },
  {enDataNotSuitableForRegression, frDataNotSuitableForRegression, esDataNotSuitableForRegression, deDataNotSuitableForRegression, ptDataNotSuitableForRegression, },
  {enDataTab, frDataTab, esDataTab, deDataTab, ptDataTab, },
  {enDecimal, frDecimal, esDecimal, deDecimal, ptDecimal, },
  {enDefaultSetting, frDefaultSetting, esDefaultSetting, deDefaultSetting, ptDefaultSetting, },
  {enDeg, frDeg, esDeg, deDeg, ptDeg, },
  {enDegres, frDegres, esDegres, deDegres, ptDegres, },
  {enDeleteFunction, frDeleteFunction, esDeleteFunction, deDeleteFunction, ptDeleteFunction, },
  {enDeleteScript, frDeleteScript, esDeleteScript, deDeleteScript, ptDeleteScript, },
  {enDeleteSequence, frDeleteSequence, esDeleteSequence, deDeleteSequence, ptDeleteSequence, },
  {enDerivateNumber, frDerivateNumber, esDerivateNumber, deDerivateNumber, ptDerivateNumber, },
  {enDerivativeFunctionColumn, frDerivativeFunctionColumn, esDerivativeFunctionColumn, deDerivativeFunctionColumn, ptDerivativeFunctionColumn, },
  {enDeterminant, frDeterminant, esDeterminant, deDeterminant, ptDeterminant, },
  {enDeviation, frDeviation, esDeviation, deDeviation, ptDeviation, },
  {enDeviationDefinition, frDeviationDefinition, esDeviationDefinition, deDeviationDefinition, ptDeviationDefinition, },
  {enDimension, frDimension, esDimension, deDimension, ptDimension, },
  {enDisplayMode, frDisplayMode, esDisplayMode, deDisplayMode, ptDisplayMode, },
  {enDisplayValues, frDisplayValues, esDisplayValues, deDisplayValues, ptDisplayValues, },
  {enDoubleRecurrence, frDoubleRecurrence, esDoubleRecurrence, deDoubleRecurrence, ptDoubleRecurrence, },
  {enEdition2D, frEdition2D, esEdition2D, deEdition2D, ptEdition2D, },
  {enEditionLinear, frEditionLinear, esEditionLinear, deEditionLinear, ptEditionLinear, },
  {enEditionMode, frEditionMode, esEditionMode, deEditionMode, ptEditionMode, },
  {enEmpty, frEmpty, esEmpty, deEmpty, ptEmpty, },
  {enEmptyExpressionBox0, frEmptyExpressionBox0, esEmptyExpressionBox0, deEmptyExpressionBox0, ptEmptyExpressionBox0, },
  {enEmptyExpressionBox1, frEmptyExpressionBox1, esEmptyExpressionBox1, deEmptyExpressionBox1, ptEmptyExpressionBox1, },
  {enEmptyExpressionBox2, frEmptyExpressionBox2, esEmptyExpressionBox2, deEmptyExpressionBox2, ptEmptyExpressionBox2, },
  {enEmptyFunctionBox0, frEmptyFunctionBox0, esEmptyFunctionBox0, deEmptyFunctionBox0, ptEmptyFunctionBox0, },
  {enEmptyFunctionBox1, frEmptyFunctionBox1, esEmptyFunctionBox1, deEmptyFunctionBox1, ptEmptyFunctionBox1, },
  {enEmptyFunctionBox2, frEmptyFunctionBox2, esEmptyFunctionBox2, deEmptyFunctionBox2, ptEmptyFunctionBox2, },
  {enEnableCharacters, frEnableCharacters, esEnableCharacters, deEnableCharacters, ptEnableCharacters, },
  {enEnterEquation, frEnterEquation, esEnterEquation, deEnterEquation, ptEnterEquation, },
  {enExamMode, frExamMode, esExamMode, deExamMode, ptExamMode, },
  {enExamModeActive, frExamModeActive, esExamModeActive, deExamModeActive, ptExamModeActive, },
  {enExecuteScript, frExecuteScript, esExecuteScript, deExecuteScript, ptExecuteScript, },
  {enExitExamMode1, frExitExamMode1, esExitExamMode1, deExitExamMode1, ptExitExamMode1, },
  {enExitExamMode2, frExitExamMode2, esExitExamMode2, deExitExamMode2, ptExitExamMode2, },
  {enExplicit, frExplicit, esExplicit, deExplicit, ptExplicit, },
  {enExponential, frExponential, esExponential, deExponential, ptExponential, },
  {enExponentialLaw, frExponentialLaw, esExponentialLaw, deExponentialLaw, ptExponentialLaw, },
  {enExpressions, frExpressions, esExpressions, deExpressions, ptExpressions, },
  {enFillWithFormula, frFillWithFormula, esFillWithFormula, deFillWithFormula, ptFillWithFormula, },
  {enFirstQuartile, frFirstQuartile, esFirstQuartile, deFirstQuartile, ptFirstQuartile, },
  {enFirstTermIndex, frFirstTermIndex, esFirstTermIndex, deFirstTermIndex, ptFirstTermIndex, },
  {enFloor, frFloor, esFloor, deFloor, ptFloor, },
  {enFluctuation, frFluctuation, esFluctuation, deFluctuation, ptFluctuation, },
  {enForbiddenValue, frForbiddenValue, esForbiddenValue, deForbiddenValue, ptForbiddenValue, },
  {enFracPart, frFracPart, esFracPart, deFracPart, ptFracPart, },
  {enFrequency, frFrequency, esFrequency, deFrequency, ptFrequency, },
  {enFunctionApp, frFunctionApp, esFunctionApp, deFunctionApp, ptFunctionApp, },
  {enFunctionAppCapital, frFunctionAppCapital, esFunctionAppCapital, deFunctionAppCapital, ptFunctionAppCapital, },
  {enFunctionColor, frFunctionColor, esFunctionColor, deFunctionColor, ptFunctionColor, },
  {enFunctionColumn, frFunctionColumn, esFunctionColumn, deFunctionColumn, ptFunctionColumn, },
  {enFunctionOptions, frFunctionOptions, esFunctionOptions, deFunctionOptions, ptFunctionOptions, },
  {enFunctionTab, frFunctionTab, esFunctionTab, deFunctionTab, ptFunctionTab, },
  {enFunctions, frFunctions, esFunctions, deFunctions, ptFunctions, },
  {enFunctionsAndVariables, frFunctionsAndVariables, esFunctionsAndVariables, deFunctionsAndVariables, ptFunctionsAndVariables, },
  {enGoto, frGoto, esGoto, deGoto, ptGoto, },
  {enGraphTab, frGraphTab, esGraphTab, deGraphTab, ptGraphTab, },
  {enGreatCommonDivisor, frGreatCommonDivisor, esGreatCommonDivisor, deGreatCommonDivisor, ptGreatCommonDivisor, },
  {enHardwareTestLaunch1, frHardwareTestLaunch1, esHardwareTestLaunch1, deHardwareTestLaunch1, ptHardwareTestLaunch1, },
  {enHardwareTestLaunch2, frHardwareTestLaunch2, esHardwareTestLaunch2, deHardwareTestLaunch2, ptHardwareTestLaunch2, },
  {enHardwareTestLaunch3, frHardwareTestLaunch3, esHardwareTestLaunch3, deHardwareTestLaunch3, ptHardwareTestLaunch3, },
  {enHardwareTestLaunch4, frHardwareTestLaunch4, esHardwareTestLaunch4, deHardwareTestLaunch4, ptHardwareTestLaunch4, },
  {enHideDerivativeColumn, frHideDerivativeColumn, esHideDerivativeColumn, deHideDerivativeColumn, ptHideDerivativeColumn, },
  {enHistogramSet, frHistogramSet, esHistogramSet, deHistogramSet, ptHistogramSet, },
  {enHistogramTab, frHistogramTab, esHistogramTab, deHistogramTab, ptHistogramTab, },
  {enHyperbolicCosine, frHyperbolicCosine, esHyperbolicCosine, deHyperbolicCosine, ptHyperbolicCosine, },
  {enHyperbolicSine, frHyperbolicSine, esHyperbolicSine, deHyperbolicSine, ptHyperbolicSine, },
  {enHyperbolicTangent, frHyperbolicTangent, esHyperbolicTangent, deHyperbolicTangent, ptHyperbolicTangent, },
  {enHyperbolicTrigonometry, frHyperbolicTrigonometry, esHyperbolicTrigonometry, deHyperbolicTrigonometry, ptHyperbolicTrigonometry, },
  {enIdentity, frIdentity, esIdentity, deIdentity, ptIdentity, },
  {enImaginaryPart, frImaginaryPart, esImaginaryPart, deImaginaryPart, ptImaginaryPart, },
  {enImportList, frImportList, esImportList, deImportList, ptImportList, },
  {enInfiniteNumberOfSolutions, frInfiniteNumberOfSolutions, esInfiniteNumberOfSolutions, deInfiniteNumberOfSolutions, ptInfiniteNumberOfSolutions, },
  {enInitialization, frInitialization, esInitialization, deInitialization, ptInitialization, },
  {enIntegral, frIntegral, esIntegral, deIntegral, ptIntegral, },
  {enInterquartileRange, frInterquartileRange, esInterquartileRange, deInterquartileRange, ptInterquartileRange, },
  {enIntersection, frIntersection, esIntersection, deIntersection, ptIntersection, },
  {enInterval, frInterval, esInterval, deInterval, ptInterval, },
  {enIntervalDefinition, frIntervalDefinition, esIntervalDefinition, deIntervalDefinition, ptIntervalDefinition, },
  {enIntervalSet, frIntervalSet, esIntervalSet, deIntervalSet, ptIntervalSet, },
  {enInvSort, frInvSort, esInvSort, deInvSort, ptInvSort, },
  {enInverse, frInverse, esInverse, deInverse, ptInverse, },
  {enInverseHyperbolicCosine, frInverseHyperbolicCosine, esInverseHyperbolicCosine, deInverseHyperbolicCosine, ptInverseHyperbolicCosine, },
  {enInverseHyperbolicSine, frInverseHyperbolicSine, esInverseHyperbolicSine, deInverseHyperbolicSine, ptInverseHyperbolicSine, },
  {enInverseHyperbolicTangent, frInverseHyperbolicTangent, esInverseHyperbolicTangent, deInverseHyperbolicTangent, ptInverseHyperbolicTangent, },
  {enLambdaExponentialDefinition, frLambdaExponentialDefinition, esLambdaExponentialDefinition, deLambdaExponentialDefinition, ptLambdaExponentialDefinition, },
  {enLambdaPoissonDefinition, frLambdaPoissonDefinition, esLambdaPoissonDefinition, deLambdaPoissonDefinition, ptLambdaPoissonDefinition, },
  {enLanguage, frLanguage, esLanguage, deLanguage, ptLanguage, },
  {enLeastCommonMultiple, frLeastCommonMultiple, esLeastCommonMultiple, deLeastCommonMultiple, ptLeastCommonMultiple, },
  {enLinear, frLinear, esLinear, deLinear, ptLinear, },
  {enLists, frLists, esLists, deLists, ptLists, },
  {enLogarithmic, frLogarithmic, esLogarithmic, deLogarithmic, ptLogarithmic, },
  {enLogistic, frLogistic, esLogistic, deLogistic, ptLogistic, },
  {enLoopsAndTests, frLoopsAndTests, esLoopsAndTests, deLoopsAndTests, ptLoopsAndTests, },
  {enLowBattery, frLowBattery, esLowBattery, deLowBattery, ptLowBattery, },
  {enMatrices, frMatrices, esMatrices, deMatrices, ptMatrices, },
  {enMaximum, frMaximum, esMaximum, deMaximum, ptMaximum, },
  {enMean, frMean, esMean, deMean, ptMean, },
  {enMeanDefinition, frMeanDefinition, esMeanDefinition, deMeanDefinition, ptMeanDefinition, },
  {enMeanDot, frMeanDot, esMeanDot, deMeanDot, ptMeanDot, },
  {enMedian, frMedian, esMedian, deMedian, ptMedian, },
  {enMinimum, frMinimum, esMinimum, deMinimum, ptMinimum, },
  {enModules, frModules, esModules, deModules, ptModules, },
  {enMove, frMove, esMove, deMove, ptMove, },
  {enNColumn, frNColumn, esNColumn, deNColumn, ptNColumn, },
  {enNEnd, frNEnd, esNEnd, deNEnd, ptNEnd, },
  {enNStart, frNStart, esNStart, deNStart, ptNStart, },
  {enNameCannotStartWithNumber, frNameCannotStartWithNumber, esNameCannotStartWithNumber, deNameCannotStartWithNumber, ptNameCannotStartWithNumber, },
  {enNameTaken, frNameTaken, esNameTaken, deNameTaken, ptNameTaken, },
  {enNameTooLong, frNameTooLong, esNameTooLong, deNameTooLong, ptNameTooLong, },
  {enNewMatrix, frNewMatrix, esNewMatrix, deNewMatrix, ptNewMatrix, },
  {enNext, frNext, esNext, deNext, ptNext, },
  {enNoActivatedFunction, frNoActivatedFunction, esNoActivatedFunction, deNoActivatedFunction, ptNoActivatedFunction, },
  {enNoActivatedSequence, frNoActivatedSequence, esNoActivatedSequence, deNoActivatedSequence, ptNoActivatedSequence, },
  {enNoDataToPlot, frNoDataToPlot, esNoDataToPlot, deNoDataToPlot, ptNoDataToPlot, },
  {enNoFunction, frNoFunction, esNoFunction, deNoFunction, ptNoFunction, },
  {enNoFunctionToDelete, frNoFunctionToDelete, esNoFunctionToDelete, deNoFunctionToDelete, ptNoFunctionToDelete, },
  {enNoIntersectionFound, frNoIntersectionFound, esNoIntersectionFound, deNoIntersectionFound, ptNoIntersectionFound, },
  {enNoMaximumFound, frNoMaximumFound, esNoMaximumFound, deNoMaximumFound, ptNoMaximumFound, },
  {enNoMinimumFound, frNoMinimumFound, esNoMinimumFound, deNoMinimumFound, ptNoMinimumFound, },
  {enNoPreimageFound, frNoPreimageFound, esNoPreimageFound, deNoPreimageFound, ptNoPreimageFound, },
  {enNoSequence, frNoSequence, esNoSequence, deNoSequence, ptNoSequence, },
  {enNoSolutionEquation, frNoSolutionEquation, esNoSolutionEquation, deNoSolutionEquation, ptNoSolutionEquation, },
  {enNoSolutionInterval, frNoSolutionInterval, esNoSolutionInterval, deNoSolutionInterval, ptNoSolutionInterval, },
  {enNoSolutionSystem, frNoSolutionSystem, esNoSolutionSystem, deNoSolutionSystem, ptNoSolutionSystem, },
  {enNoValueToCompute, frNoValueToCompute, esNoValueToCompute, deNoValueToCompute, ptNoValueToCompute, },
  {enNoZeroFound, frNoZeroFound, esNoZeroFound, deNoZeroFound, ptNoZeroFound, },
  {enNonLinearSystem, frNonLinearSystem, esNonLinearSystem, deNonLinearSystem, ptNonLinearSystem, },
  {enNormal, frNormal, esNormal, deNormal, ptNormal, },
  {enNormalLaw, frNormalLaw, esNormalLaw, deNormalLaw, ptNormalLaw, },
  {enNthRoot, frNthRoot, esNthRoot, deNthRoot, ptNthRoot, },
  {enNumberOfDots, frNumberOfDots, esNumberOfDots, deNumberOfDots, ptNumberOfDots, },
  {enOk, frOk, esOk, deOk, ptOk, },
  {enOnlyFirstSolutionsDisplayed0, frOnlyFirstSolutionsDisplayed0, esOnlyFirstSolutionsDisplayed0, deOnlyFirstSolutionsDisplayed0, ptOnlyFirstSolutionsDisplayed0, },
  {enOnlyFirstSolutionsDisplayed1, frOnlyFirstSolutionsDisplayed1, esOnlyFirstSolutionsDisplayed1, deOnlyFirstSolutionsDisplayed1, ptOnlyFirstSolutionsDisplayed1, },
  {enOr, frOr, esOr, deOr, ptOr, },
  {enOrthonormal, frOrthonormal, esOrthonormal, deOrthonormal, ptOrthonormal, },
  {enPermutation, frPermutation, esPermutation, dePermutation, ptPermutation, },
  {enPlot, frPlot, esPlot, dePlot, ptPlot, },
  {enPlotOptions, frPlotOptions, esPlotOptions, dePlotOptions, ptPlotOptions, },
  {enPoisson, frPoisson, esPoisson, dePoisson, ptPoisson, },
  {enPoissonLaw, frPoissonLaw, esPoissonLaw, dePoissonLaw, ptPoissonLaw, },
  {enPolar, frPolar, esPolar, dePolar, ptPolar, },
  {enPolynomeHasNoRealSolution0, frPolynomeHasNoRealSolution0, esPolynomeHasNoRealSolution0, dePolynomeHasNoRealSolution0, ptPolynomeHasNoRealSolution0, },
  {enPolynomeHasNoRealSolution1, frPolynomeHasNoRealSolution1, esPolynomeHasNoRealSolution1, dePolynomeHasNoRealSolution1, ptPolynomeHasNoRealSolution1, },
  {enPoolMemoryFull1, frPoolMemoryFull1, esPoolMemoryFull1, dePoolMemoryFull1, ptPoolMemoryFull1, },
  {enPoolMemoryFull2, frPoolMemoryFull2, esPoolMemoryFull2, dePoolMemoryFull2, ptPoolMemoryFull2, },
  {enPower, frPower, esPower, dePower, ptPower, },
  {enPrediction, frPrediction, esPrediction, dePrediction, ptPrediction, },
  {enPrediction95, frPrediction95, esPrediction95, dePrediction95, ptPrediction95, },
  {enPreimage, frPreimage, esPreimage, dePreimage, ptPreimage, },
  {enPrimeFactorDecomposition, frPrimeFactorDecomposition, esPrimeFactorDecomposition, dePrimeFactorDecomposition, ptPrimeFactorDecomposition, },
  {enProbaApp, frProbaApp, esProbaApp, deProbaApp, ptProbaApp, },
  {enProbaAppCapital, frProbaAppCapital, esProbaAppCapital, deProbaAppCapital, ptProbaAppCapital, },
  {enProbability, frProbability, esProbability, deProbability, ptProbability, },
  {enProduct, frProduct, esProduct, deProduct, ptProduct, },
  {enPython1J, frPython1J, esPython1J, dePython1J, ptPython1J, },
  {enPythonAbs, frPythonAbs, esPythonAbs, dePythonAbs, ptPythonAbs, },
  {enPythonAcos, frPythonAcos, esPythonAcos, dePythonAcos, ptPythonAcos, },
  {enPythonAcosh, frPythonAcosh, esPythonAcosh, dePythonAcosh, ptPythonAcosh, },
  {enPythonAmpersand, frPythonAmpersand, esPythonAmpersand, dePythonAmpersand, ptPythonAmpersand, },
  {enPythonAsin, frPythonAsin, esPythonAsin, dePythonAsin, ptPythonAsin, },
  {enPythonAsinh, frPythonAsinh, esPythonAsinh, dePythonAsinh, ptPythonAsinh, },
  {enPythonAtan, frPythonAtan, esPythonAtan, dePythonAtan, ptPythonAtan, },
  {enPythonAtan2, frPythonAtan2, esPythonAtan2, dePythonAtan2, ptPythonAtan2, },
  {enPythonAtanh, frPythonAtanh, esPythonAtanh, dePythonAtanh, ptPythonAtanh, },
  {enPythonBin, frPythonBin, esPythonBin, dePythonBin, ptPythonBin, },
  {enPythonCeil, frPythonCeil, esPythonCeil, dePythonCeil, ptPythonCeil, },
  {enPythonChoice, frPythonChoice, esPythonChoice, dePythonChoice, ptPythonChoice, },
  {enPythonCmathFunction, frPythonCmathFunction, esPythonCmathFunction, dePythonCmathFunction, ptPythonCmathFunction, },
  {enPythonColor, frPythonColor, esPythonColor, dePythonColor, ptPythonColor, },
  {enPythonComplex, frPythonComplex, esPythonComplex, dePythonComplex, ptPythonComplex, },
  {enPythonConstantE, frPythonConstantE, esPythonConstantE, dePythonConstantE, ptPythonConstantE, },
  {enPythonConstantPi, frPythonConstantPi, esPythonConstantPi, dePythonConstantPi, ptPythonConstantPi, },
  {enPythonCopySign, frPythonCopySign, esPythonCopySign, dePythonCopySign, ptPythonCopySign, },
  {enPythonCos, frPythonCos, esPythonCos, dePythonCos, ptPythonCos, },
  {enPythonCosh, frPythonCosh, esPythonCosh, dePythonCosh, ptPythonCosh, },
  {enPythonDegrees, frPythonDegrees, esPythonDegrees, dePythonDegrees, ptPythonDegrees, },
  {enPythonDivMod, frPythonDivMod, esPythonDivMod, dePythonDivMod, ptPythonDivMod, },
  {enPythonDrawString, frPythonDrawString, esPythonDrawString, dePythonDrawString, ptPythonDrawString, },
  {enPythonErf, frPythonErf, esPythonErf, dePythonErf, ptPythonErf, },
  {enPythonErfc, frPythonErfc, esPythonErfc, dePythonErfc, ptPythonErfc, },
  {enPythonEval, frPythonEval, esPythonEval, dePythonEval, ptPythonEval, },
  {enPythonExp, frPythonExp, esPythonExp, dePythonExp, ptPythonExp, },
  {enPythonExpm1, frPythonExpm1, esPythonExpm1, dePythonExpm1, ptPythonExpm1, },
  {enPythonFabs, frPythonFabs, esPythonFabs, dePythonFabs, ptPythonFabs, },
  {enPythonFillRect, frPythonFillRect, esPythonFillRect, dePythonFillRect, ptPythonFillRect, },
  {enPythonFloat, frPythonFloat, esPythonFloat, dePythonFloat, ptPythonFloat, },
  {enPythonFloor, frPythonFloor, esPythonFloor, dePythonFloor, ptPythonFloor, },
  {enPythonFmod, frPythonFmod, esPythonFmod, dePythonFmod, ptPythonFmod, },
  {enPythonFrExp, frPythonFrExp, esPythonFrExp, dePythonFrExp, ptPythonFrExp, },
  {enPythonGamma, frPythonGamma, esPythonGamma, dePythonGamma, ptPythonGamma, },
  {enPythonGetPixel, frPythonGetPixel, esPythonGetPixel, dePythonGetPixel, ptPythonGetPixel, },
  {enPythonGetrandbits, frPythonGetrandbits, esPythonGetrandbits, dePythonGetrandbits, ptPythonGetrandbits, },
  {enPythonHex, frPythonHex, esPythonHex, dePythonHex, ptPythonHex, },
  {enPythonImag, frPythonImag, esPythonImag, dePythonImag, ptPythonImag, },
  {enPythonImportCmath, frPythonImportCmath, esPythonImportCmath, dePythonImportCmath, ptPythonImportCmath, },
  {enPythonImportFromCmath, frPythonImportFromCmath, esPythonImportFromCmath, dePythonImportFromCmath, ptPythonImportFromCmath, },
  {enPythonImportFromKandinsky, frPythonImportFromKandinsky, esPythonImportFromKandinsky, dePythonImportFromKandinsky, ptPythonImportFromKandinsky, },
  {enPythonImportFromMath, frPythonImportFromMath, esPythonImportFromMath, dePythonImportFromMath, ptPythonImportFromMath, },
  {enPythonImportFromRandom, frPythonImportFromRandom, esPythonImportFromRandom, dePythonImportFromRandom, ptPythonImportFromRandom, },
  {enPythonImportFromTurtle, frPythonImportFromTurtle, esPythonImportFromTurtle, dePythonImportFromTurtle, ptPythonImportFromTurtle, },
  {enPythonImportKandinsky, frPythonImportKandinsky, esPythonImportKandinsky, dePythonImportKandinsky, ptPythonImportKandinsky, },
  {enPythonImportMath, frPythonImportMath, esPythonImportMath, dePythonImportMath, ptPythonImportMath, },
  {enPythonImportRandom, frPythonImportRandom, esPythonImportRandom, dePythonImportRandom, ptPythonImportRandom, },
  {enPythonImportTurtle, frPythonImportTurtle, esPythonImportTurtle, dePythonImportTurtle, ptPythonImportTurtle, },
  {enPythonInput, frPythonInput, esPythonInput, dePythonInput, ptPythonInput, },
  {enPythonInt, frPythonInt, esPythonInt, dePythonInt, ptPythonInt, },
  {enPythonIsFinite, frPythonIsFinite, esPythonIsFinite, dePythonIsFinite, ptPythonIsFinite, },
  {enPythonIsInfinite, frPythonIsInfinite, esPythonIsInfinite, dePythonIsInfinite, ptPythonIsInfinite, },
  {enPythonIsNaN, frPythonIsNaN, esPythonIsNaN, dePythonIsNaN, ptPythonIsNaN, },
  {enPythonKandinskyFunction, frPythonKandinskyFunction, esPythonKandinskyFunction, dePythonKandinskyFunction, ptPythonKandinskyFunction, },
  {enPythonLF, frPythonLF, esPythonLF, dePythonLF, ptPythonLF, },
  {enPythonLdexp, frPythonLdexp, esPythonLdexp, dePythonLdexp, ptPythonLdexp, },
  {enPythonLength, frPythonLength, esPythonLength, dePythonLength, ptPythonLength, },
  {enPythonLgamma, frPythonLgamma, esPythonLgamma, dePythonLgamma, ptPythonLgamma, },
  {enPythonLog, frPythonLog, esPythonLog, dePythonLog, ptPythonLog, },
  {enPythonLog10, frPythonLog10, esPythonLog10, dePythonLog10, ptPythonLog10, },
  {enPythonLog2, frPythonLog2, esPythonLog2, dePythonLog2, ptPythonLog2, },
  {enPythonMathFunction, frPythonMathFunction, esPythonMathFunction, dePythonMathFunction, ptPythonMathFunction, },
  {enPythonMax, frPythonMax, esPythonMax, dePythonMax, ptPythonMax, },
  {enPythonMin, frPythonMin, esPythonMin, dePythonMin, ptPythonMin, },
  {enPythonModf, frPythonModf, esPythonModf, dePythonModf, ptPythonModf, },
  {enPythonOct, frPythonOct, esPythonOct, dePythonOct, ptPythonOct, },
  {enPythonPercent, frPythonPercent, esPythonPercent, dePythonPercent, ptPythonPercent, },
  {enPythonPhase, frPythonPhase, esPythonPhase, dePythonPhase, ptPythonPhase, },
  {enPythonPolar, frPythonPolar, esPythonPolar, dePythonPolar, ptPythonPolar, },
  {enPythonPound, frPythonPound, esPythonPound, dePythonPound, ptPythonPound, },
  {enPythonPower, frPythonPower, esPythonPower, dePythonPower, ptPythonPower, },
  {enPythonPrint, frPythonPrint, esPythonPrint, dePythonPrint, ptPythonPrint, },
  {enPythonRadians, frPythonRadians, esPythonRadians, dePythonRadians, ptPythonRadians, },
  {enPythonRandint, frPythonRandint, esPythonRandint, dePythonRandint, ptPythonRandint, },
  {enPythonRandom, frPythonRandom, esPythonRandom, dePythonRandom, ptPythonRandom, },
  {enPythonRandomFunction, frPythonRandomFunction, esPythonRandomFunction, dePythonRandomFunction, ptPythonRandomFunction, },
  {enPythonRandrange, frPythonRandrange, esPythonRandrange, dePythonRandrange, ptPythonRandrange, },
  {enPythonRangeStartStop, frPythonRangeStartStop, esPythonRangeStartStop, dePythonRangeStartStop, ptPythonRangeStartStop, },
  {enPythonRangeStop, frPythonRangeStop, esPythonRangeStop, dePythonRangeStop, ptPythonRangeStop, },
  {enPythonReal, frPythonReal, esPythonReal, dePythonReal, ptPythonReal, },
  {enPythonRect, frPythonRect, esPythonRect, dePythonRect, ptPythonRect, },
  {enPythonRound, frPythonRound, esPythonRound, dePythonRound, ptPythonRound, },
  {enPythonSeed, frPythonSeed, esPythonSeed, dePythonSeed, ptPythonSeed, },
  {enPythonSetPixel, frPythonSetPixel, esPythonSetPixel, dePythonSetPixel, ptPythonSetPixel, },
  {enPythonSin, frPythonSin, esPythonSin, dePythonSin, ptPythonSin, },
  {enPythonSingleQuote, frPythonSingleQuote, esPythonSingleQuote, dePythonSingleQuote, ptPythonSingleQuote, },
  {enPythonSinh, frPythonSinh, esPythonSinh, dePythonSinh, ptPythonSinh, },
  {enPythonSorted, frPythonSorted, esPythonSorted, dePythonSorted, ptPythonSorted, },
  {enPythonSqrt, frPythonSqrt, esPythonSqrt, dePythonSqrt, ptPythonSqrt, },
  {enPythonSum, frPythonSum, esPythonSum, dePythonSum, ptPythonSum, },
  {enPythonSymbolExp, frPythonSymbolExp, esPythonSymbolExp, dePythonSymbolExp, ptPythonSymbolExp, },
  {enPythonTab, frPythonTab, esPythonTab, dePythonTab, ptPythonTab, },
  {enPythonTan, frPythonTan, esPythonTan, dePythonTan, ptPythonTan, },
  {enPythonTanh, frPythonTanh, esPythonTanh, dePythonTanh, ptPythonTanh, },
  {enPythonTrunc, frPythonTrunc, esPythonTrunc, dePythonTrunc, ptPythonTrunc, },
  {enPythonTurtleBackward, frPythonTurtleBackward, esPythonTurtleBackward, dePythonTurtleBackward, ptPythonTurtleBackward, },
  {enPythonTurtleBlack, frPythonTurtleBlack, esPythonTurtleBlack, dePythonTurtleBlack, ptPythonTurtleBlack, },
  {enPythonTurtleBlue, frPythonTurtleBlue, esPythonTurtleBlue, dePythonTurtleBlue, ptPythonTurtleBlue, },
  {enPythonTurtleBrown, frPythonTurtleBrown, esPythonTurtleBrown, dePythonTurtleBrown, ptPythonTurtleBrown, },
  {enPythonTurtleCircle, frPythonTurtleCircle, esPythonTurtleCircle, dePythonTurtleCircle, ptPythonTurtleCircle, },
  {enPythonTurtleColor, frPythonTurtleColor, esPythonTurtleColor, dePythonTurtleColor, ptPythonTurtleColor, },
  {enPythonTurtleForward, frPythonTurtleForward, esPythonTurtleForward, dePythonTurtleForward, ptPythonTurtleForward, },
  {enPythonTurtleFunction, frPythonTurtleFunction, esPythonTurtleFunction, dePythonTurtleFunction, ptPythonTurtleFunction, },
  {enPythonTurtleGoto, frPythonTurtleGoto, esPythonTurtleGoto, dePythonTurtleGoto, ptPythonTurtleGoto, },
  {enPythonTurtleGreen, frPythonTurtleGreen, esPythonTurtleGreen, dePythonTurtleGreen, ptPythonTurtleGreen, },
  {enPythonTurtleGrey, frPythonTurtleGrey, esPythonTurtleGrey, dePythonTurtleGrey, ptPythonTurtleGrey, },
  {enPythonTurtleHeading, frPythonTurtleHeading, esPythonTurtleHeading, dePythonTurtleHeading, ptPythonTurtleHeading, },
  {enPythonTurtleHideturtle, frPythonTurtleHideturtle, esPythonTurtleHideturtle, dePythonTurtleHideturtle, ptPythonTurtleHideturtle, },
  {enPythonTurtleIsdown, frPythonTurtleIsdown, esPythonTurtleIsdown, dePythonTurtleIsdown, ptPythonTurtleIsdown, },
  {enPythonTurtleLeft, frPythonTurtleLeft, esPythonTurtleLeft, dePythonTurtleLeft, ptPythonTurtleLeft, },
  {enPythonTurtleOrange, frPythonTurtleOrange, esPythonTurtleOrange, dePythonTurtleOrange, ptPythonTurtleOrange, },
  {enPythonTurtlePendown, frPythonTurtlePendown, esPythonTurtlePendown, dePythonTurtlePendown, ptPythonTurtlePendown, },
  {enPythonTurtlePensize, frPythonTurtlePensize, esPythonTurtlePensize, dePythonTurtlePensize, ptPythonTurtlePensize, },
  {enPythonTurtlePenup, frPythonTurtlePenup, esPythonTurtlePenup, dePythonTurtlePenup, ptPythonTurtlePenup, },
  {enPythonTurtlePink, frPythonTurtlePink, esPythonTurtlePink, dePythonTurtlePink, ptPythonTurtlePink, },
  {enPythonTurtlePosition, frPythonTurtlePosition, esPythonTurtlePosition, dePythonTurtlePosition, ptPythonTurtlePosition, },
  {enPythonTurtlePurple, frPythonTurtlePurple, esPythonTurtlePurple, dePythonTurtlePurple, ptPythonTurtlePurple, },
  {enPythonTurtleRed, frPythonTurtleRed, esPythonTurtleRed, dePythonTurtleRed, ptPythonTurtleRed, },
  {enPythonTurtleReset, frPythonTurtleReset, esPythonTurtleReset, dePythonTurtleReset, ptPythonTurtleReset, },
  {enPythonTurtleRight, frPythonTurtleRight, esPythonTurtleRight, dePythonTurtleRight, ptPythonTurtleRight, },
  {enPythonTurtleSetheading, frPythonTurtleSetheading, esPythonTurtleSetheading, dePythonTurtleSetheading, ptPythonTurtleSetheading, },
  {enPythonTurtleSetposition, frPythonTurtleSetposition, esPythonTurtleSetposition, dePythonTurtleSetposition, ptPythonTurtleSetposition, },
  {enPythonTurtleShowturtle, frPythonTurtleShowturtle, esPythonTurtleShowturtle, dePythonTurtleShowturtle, ptPythonTurtleShowturtle, },
  {enPythonTurtleSpeed, frPythonTurtleSpeed, esPythonTurtleSpeed, dePythonTurtleSpeed, ptPythonTurtleSpeed, },
  {enPythonTurtleWhite, frPythonTurtleWhite, esPythonTurtleWhite, dePythonTurtleWhite, ptPythonTurtleWhite, },
  {enPythonTurtleYellow, frPythonTurtleYellow, esPythonTurtleYellow, dePythonTurtleYellow, ptPythonTurtleYellow, },
  {enPythonUniform, frPythonUniform, esPythonUniform, dePythonUniform, ptPythonUniform, },
  {enPythonVerticalBar, frPythonVerticalBar, esPythonVerticalBar, dePythonVerticalBar, ptPythonVerticalBar, },
  {enQuadratic, frQuadratic, esQuadratic, deQuadratic, ptQuadratic, },
  {enQuartic, frQuartic, esQuartic, deQuartic, ptQuartic, },
  {enQuotient, frQuotient, esQuotient, deQuotient, ptQuotient, },
  {enRad, frRad, esRad, deRad, ptRad, },
  {enRadian, frRadian, esRadian, deRadian, ptRadian, },
  {enRandomAndApproximation, frRandomAndApproximation, esRandomAndApproximation, deRandomAndApproximation, ptRandomAndApproximation, },
  {enRandomFloat, frRandomFloat, esRandomFloat, deRandomFloat, ptRandomFloat, },
  {enRandomInteger, frRandomInteger, esRandomInteger, deRandomInteger, ptRandomInteger, },
  {enRange, frRange, esRange, deRange, ptRange, },
  {enReal, frReal, esReal, deReal, ptReal, },
  {enRealPart, frRealPart, esRealPart, deRealPart, ptRealPart, },
  {enRectangleWidth, frRectangleWidth, esRectangleWidth, deRectangleWidth, ptRectangleWidth, },
  {enReg, frReg, esReg, deReg, ptReg, },
  {enRegression, frRegression, esRegression, deRegression, ptRegression, },
  {enRegressionApp, frRegressionApp, esRegressionApp, deRegressionApp, ptRegressionApp, },
  {enRegressionAppCapital, frRegressionAppCapital, esRegressionAppCapital, deRegressionAppCapital, ptRegressionAppCapital, },
  {enRegressionCurve, frRegressionCurve, esRegressionCurve, deRegressionCurve, ptRegressionCurve, },
  {enRemainder, frRemainder, esRemainder, deRemainder, ptRemainder, },
  {enRename, frRename, esRename, deRename, ptRename, },
  {enRepetitionNumber, frRepetitionNumber, esRepetitionNumber, deRepetitionNumber, ptRepetitionNumber, },
  {enRequireEquation, frRequireEquation, esRequireEquation, deRequireEquation, ptRequireEquation, },
  {enReservedName, frReservedName, esReservedName, deReservedName, ptReservedName, },
  {enResolveEquation, frResolveEquation, esResolveEquation, deResolveEquation, ptResolveEquation, },
  {enResolveSystem, frResolveSystem, esResolveSystem, deResolveSystem, ptResolveSystem, },
  {enRoundAbscissa, frRoundAbscissa, esRoundAbscissa, deRoundAbscissa, ptRoundAbscissa, },
  {enRounding, frRounding, esRounding, deRounding, ptRounding, },
  {enSampleStandardDeviationS, frSampleStandardDeviationS, esSampleStandardDeviationS, deSampleStandardDeviationS, ptSampleStandardDeviationS, },
  {enSci, frSci, esSci, deSci, ptSci, },
  {enScientific, frScientific, esScientific, deScientific, ptScientific, },
  {enScriptOptions, frScriptOptions, esScriptOptions, deScriptOptions, ptScriptOptions, },
  {enSearchInverval, frSearchInverval, esSearchInverval, deSearchInverval, ptSearchInverval, },
  {enSelectFirstTerm, frSelectFirstTerm, esSelectFirstTerm, deSelectFirstTerm, ptSelectFirstTerm, },
  {enSelectLastTerm, frSelectLastTerm, esSelectLastTerm, deSelectLastTerm, ptSelectLastTerm, },
  {enSelectLowerBound, frSelectLowerBound, esSelectLowerBound, deSelectLowerBound, ptSelectLowerBound, },
  {enSelectUpperBound, frSelectUpperBound, esSelectUpperBound, deSelectUpperBound, ptSelectUpperBound, },
  {enSequenceApp, frSequenceApp, esSequenceApp, deSequenceApp, ptSequenceApp, },
  {enSequenceAppCapital, frSequenceAppCapital, esSequenceAppCapital, deSequenceAppCapital, ptSequenceAppCapital, },
  {enSequenceColor, frSequenceColor, esSequenceColor, deSequenceColor, ptSequenceColor, },
  {enSequenceOptions, frSequenceOptions, esSequenceOptions, deSequenceOptions, ptSequenceOptions, },
  {enSequenceTab, frSequenceTab, esSequenceTab, deSequenceTab, ptSequenceTab, },
  {enSequenceType, frSequenceType, esSequenceType, deSequenceType, ptSequenceType, },
  {enSerialNumber, frSerialNumber, esSerialNumber, deSerialNumber, ptSerialNumber, },
  {enSettingsApp, frSettingsApp, esSettingsApp, deSettingsApp, ptSettingsApp, },
  {enSettingsAppCapital, frSettingsAppCapital, esSettingsAppCapital, deSettingsAppCapital, ptSettingsAppCapital, },
  {enSignificantFigures, frSignificantFigures, esSignificantFigures, deSignificantFigures, ptSignificantFigures, },
  {enSingleRecurrence, frSingleRecurrence, esSingleRecurrence, deSingleRecurrence, ptSingleRecurrence, },
  {enSize, frSize, esSize, deSize, ptSize, },
  {enSizes1, frSizes1, esSizes1, deSizes1, ptSizes1, },
  {enSizes2, frSizes2, esSizes2, deSizes2, ptSizes2, },
  {enSizes3, frSizes3, esSizes3, deSizes3, ptSizes3, },
  {enSkip, frSkip, esSkip, deSkip, ptSkip, },
  {enSoftwareVersion, frSoftwareVersion, esSoftwareVersion, deSoftwareVersion, ptSoftwareVersion, },
  {enSolution, frSolution, esSolution, deSolution, ptSolution, },
  {enSolverApp, frSolverApp, esSolverApp, deSolverApp, ptSolverApp, },
  {enSolverAppCapital, frSolverAppCapital, esSolverAppCapital, deSolverAppCapital, ptSolverAppCapital, },
  {enSort, frSort, esSort, deSort, ptSort, },
  {enSquareSum, frSquareSum, esSquareSum, deSquareSum, ptSquareSum, },
  {enStandardDeviation, frStandardDeviation, esStandardDeviation, deStandardDeviation, ptStandardDeviation, },
  {enStandardDeviationSigma, frStandardDeviationSigma, esStandardDeviationSigma, deStandardDeviationSigma, ptStandardDeviationSigma, },
  {enStatTab, frStatTab, esStatTab, deStatTab, ptStatTab, },
  {enStatsApp, frStatsApp, esStatsApp, deStatsApp, ptStatsApp, },
  {enStatsAppCapital, frStatsAppCapital, esStatsAppCapital, deStatsAppCapital, ptStatsAppCapital, },
  {enStep, frStep, esStep, deStep, ptStep, },
  {enStorageMemoryFull1, frStorageMemoryFull1, esStorageMemoryFull1, deStorageMemoryFull1, ptStorageMemoryFull1, },
  {enStorageMemoryFull2, frStorageMemoryFull2, esStorageMemoryFull2, deStorageMemoryFull2, ptStorageMemoryFull2, },
  {enStoreExpressionNotAllowed, frStoreExpressionNotAllowed, esStoreExpressionNotAllowed, deStoreExpressionNotAllowed, ptStoreExpressionNotAllowed, },
  {enSuccessProbability, frSuccessProbability, esSuccessProbability, deSuccessProbability, ptSuccessProbability, },
  {enSum, frSum, esSum, deSum, ptSum, },
  {enSyntaxError, frSyntaxError, esSyntaxError, deSyntaxError, ptSyntaxError, },
  {enTangent, frTangent, esTangent, deTangent, ptTangent, },
  {enTermSum, frTermSum, esTermSum, deTermSum, ptTermSum, },
  {enThirdQuartile, frThirdQuartile, esThirdQuartile, deThirdQuartile, ptThirdQuartile, },
  {enToZoom, frToZoom, esToZoom, deToZoom, ptToZoom, },
  {enTooManyVariables, frTooManyVariables, esTooManyVariables, deTooManyVariables, ptTooManyVariables, },
  {enToolbox, frToolbox, esToolbox, deToolbox, ptToolbox, },
  {enTotalSize, frTotalSize, esTotalSize, deTotalSize, ptTotalSize, },
  {enTrace, frTrace, esTrace, deTrace, ptTrace, },
  {enTranspose, frTranspose, esTranspose, deTranspose, ptTranspose, },
  {enTrigonometric, frTrigonometric, esTrigonometric, deTrigonometric, ptTrigonometric, },
  {enTrigonometrical, frTrigonometrical, esTrigonometrical, deTrigonometrical, ptTrigonometrical, },
  {enUSBConnected, frUSBConnected, esUSBConnected, deUSBConnected, ptUSBConnected, },
  {enUndefinedEquation, frUndefinedEquation, esUndefinedEquation, deUndefinedEquation, ptUndefinedEquation, },
  {enUndefinedValue, frUndefinedValue, esUndefinedValue, deUndefinedValue, ptUndefinedValue, },
  {enUniformLaw, frUniformLaw, esUniformLaw, deUniformLaw, ptUniformLaw, },
  {enUniforme, frUniforme, esUniforme, deUniforme, ptUniforme, },
  {enUnrealEquation, frUnrealEquation, esUnrealEquation, deUnrealEquation, ptUnrealEquation, },
  {enUpdateAvailable, frUpdateAvailable, esUpdateAvailable, deUpdateAvailable, ptUpdateAvailable, },
  {enUpdateMessage1, frUpdateMessage1, esUpdateMessage1, deUpdateMessage1, ptUpdateMessage1, },
  {enUpdateMessage2, frUpdateMessage2, esUpdateMessage2, deUpdateMessage2, ptUpdateMessage2, },
  {enUpdateMessage3, frUpdateMessage3, esUpdateMessage3, deUpdateMessage3, ptUpdateMessage3, },
  {enUpdateMessage4, frUpdateMessage4, esUpdateMessage4, deUpdateMessage4, ptUpdateMessage4, },
  {enUpdatePopUp, frUpdatePopUp, esUpdatePopUp, deUpdatePopUp, ptUpdatePopUp, },
  {enUseEquationModel, frUseEquationModel, esUseEquationModel, deUseEquationModel, ptUseEquationModel, },
  {enValueNotReachedByFunction, frValueNotReachedByFunction, esValueNotReachedByFunction, deValueNotReachedByFunction, ptValueNotReachedByFunction, },
  {enValueNotReachedByRegression, frValueNotReachedByRegression, esValueNotReachedByRegression, deValueNotReachedByRegression, ptValueNotReachedByRegression, },
  {enValueNotReachedBySequence, frValueNotReachedBySequence, esValueNotReachedBySequence, deValueNotReachedBySequence, ptValueNotReachedBySequence, },
  {enValues1, frValues1, esValues1, deValues1, ptValues1, },
  {enValues2, frValues2, esValues2, deValues2, ptValues2, },
  {enValues3, frValues3, esValues3, deValues3, ptValues3, },
  {enValuesTab, frValuesTab, esValuesTab, deValuesTab, ptValuesTab, },
  {enVariables, frVariables, esVariables, deVariables, ptVariables, },
  {enWarning, frWarning, esWarning, deWarning, ptWarning, },
  {enXEnd, frXEnd, esXEnd, deXEnd, ptXEnd, },
  {enXPrediction, frXPrediction, esXPrediction, deXPrediction, ptXPrediction, },
  {enXStart, frXStart, esXStart, deXStart, ptXStart, },
  {enYPrediction, frYPrediction, esYPrediction, deYPrediction, ptYPrediction, },
  {enZeros, frZeros, esZeros, deZeros, ptZeros, },
  {enZoom, frZoom, esZoom, deZoom, ptZoom, },
};

const char * translate(Message m, Language l) {
  assert(m != Message::LocalizedMessageMarker);
  int localizedMessageOffset = (int)Message::LocalizedMessageMarker+1;
  if ((int)m < localizedMessageOffset) {
    assert(universalMessages[(int)m] != nullptr);
    return universalMessages[(int)m];
  }
  int languageIndex = (int)l;
  if (l == Language::Default) {
    languageIndex = (int) GlobalPreferences::sharedGlobalPreferences()->language();
  }
  assert(languageIndex > 0);
  int messageIndex = (int)m - localizedMessageOffset;
  assert((messageIndex*NumberOfLanguages+languageIndex-1)*sizeof(char *) < sizeof(messages));
  return messages[messageIndex][languageIndex-1];
}

}
