﻿int main(){
puts("New Year Phone Survey for ACM ICPC - Health vs greeting style");
puts("Q01 Hello!");
puts(" H Hello!");
puts(" Y Yes!");
puts(" * Uhm...");
puts(" . (silence)");
puts(" @ (other)");
puts("Q02 How are you?");
puts(" H Hello!");
puts(" Y Yes!");
puts(" F Fine!");
puts(" Q Who are you?");
puts(" @ (other)");
puts("");
puts("       Q02:H Q02:Y Q02:F Q02:Q Q02:@ TOTAL");
puts(" Q01:H     2     0     1     1     1     5");
puts("         40%%    0%%   20%%   20%%   20%%  100%%");
puts("         66%%    0%%   50%%  100%%   33%%   50%%");
puts(" Q01:Y     0     1     1     0     0     2");
puts("          0%%   50%%   50%%    0%%    0%%  100%%");
puts("          0%%  100%%   50%%    0%%    0%%   20%%");
puts(" Q01:*     0     0     0     0     0     0");
puts("           -     -     -     -     -     -");
puts("          0%%    0%%    0%%    0%%    0%%    0%%");
puts(" Q01:.     1     0     0     0     2     3");
puts("         33%%    0%%    0%%    0%%   67%%  100%%");
puts("         34%%    0%%    0%%    0%%   67%%   30%%");
puts(" Q01:@     0     0     0     0     0     0");
puts("           -     -     -     -     -     -");
puts("          0%%    0%%    0%%    0%%    0%%    0%%");
puts(" TOTAL     3     1     2     1     3    10");
puts("         30%%   10%%   20%%   10%%   30%%  100%%");
puts("        100%%  100%%  100%%  100%%  100%%  100%%");
puts("");
puts("New Year Phone Survey for ACM ICPC - Politeness matrix");
puts("Q02 How are you?");
puts(" H Hello!");
puts(" Y Yes!");
puts(" F Fine!");
puts(" Q Who are you?");
puts(" @ (other)");
puts("BYE Happy New Year!");
puts(" Y You too.");
puts(" * (censored)");
puts(" @ (other)");
puts(" . (hang up)");
puts("");
puts("       BYE:Y BYE:* BYE:@ BYE:. TOTAL");
puts(" Q02:H     0     0     3     0     3");
puts("          0%%    0%%  100%%    0%%  100%%");
puts("          0%%    0%%  100%%    0%%   30%%");
puts(" Q02:Y     1     0     0     0     1");
puts(         100%%    0%%    0%%    0%%  100%%");
puts("         33%%    0%%    0%%    0%%   10%%");
puts(" Q02:F     2     0     0     0     2");
puts("        100%%    0%%    0%%    0%%  100%%");
puts("         67%%    0%%    0%%    0%%   20%%");
puts(" Q02:Q     0     1     0     0     1");
puts("          0%%  100%%    0%%    0%%  100%%");
puts("          0%%  100%%    0%%    0%%   10%%");
puts(" Q02:@     0     0     0     3     3");
puts("          0%%    0%%    0%%  100%%  100%%");
puts("          0%%    0%%    0%%  100%%   30%%");
puts(" TOTAL     3     1     3     3    10");
puts("         30%%   10%%   30%%   30%%  100%%");
puts("        100%%  100%%  100%%  100%%  100%%");
puts("");
puts("");
}
