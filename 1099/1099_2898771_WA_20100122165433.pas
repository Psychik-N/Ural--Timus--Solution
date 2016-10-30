const
 maxn=250;
type
 graphtype=array[1..maxn,1..maxn] of integer;
 listtype=array[1..maxn,1..2] of integer;
 ltype=array[1..maxn] of integer;
var
 g:graphtype;
 l:listtype;
 p:ltype;
 n:integer;

procedure init;
 var i,j:integer;
 begin
  read(n);
  while not seekeof do
   begin
    read(i,j);
    g[i,j]:=1;
    g[j,i]:=1;
   end;
 end;

procedure findway(i,j:integer);
 var q,k:integer;
  begin
   q:=i;k:=j;p[j]:=i;
   while l[q,2]<>maxint do
    begin
     p[q]:=k;k:=l[q,2];
     p[k]:=l[k,1];
     q:=l[k,1];
    end;
   p[q]:=k;
  end;

function kuo_tree:boolean;
 var i,j,q,k,v:integer;
     s:set of 1..maxn;
     more:boolean;
 begin
  kuo_tree:=true;
  repeat
   more:=false;
   for i:=1 to n do
    if l[i,2]>0 then
     for j:=1 to n do
      if (g[i,j]>0) and (p[i]<>j) then
       if (l[j,1]=0) and (l[j,2]=0)
        then if p[j]=0
         then begin
          findway(i,j);
          exit;
          end
         else begin
          g[i,j]:=-g[i,j];
          g[j,i]:=-g[j,i];
          l[j,1]:=i;l[p[j],2]:=j;
          g[j,p[j]]:=-g[j,p[j]];
          g[p[j],j]:=-g[p[j],j];
          more:=true;
         end
        else if (l[j,1]=0) and (l[j,2]>0) then
         begin
          more:=true;
          g[i,j]:=-g[i,j];g[j,i]:=-g[j,i];
          s:=[i];k:=i;v:=2;
          while l[k,v]<>maxint do
           begin k:=l[k,v];s:=s+[k];v:=3-v;end;
          k:=j;v:=2;
          while not (k in s) do
           begin k:=l[k,v];v:=3-v;end;
          if l[i,1]=0 then
           begin
            l[i,1]:=j;q:=i;v:=2;
            while q<>k do
             begin
              l[l[q,v],v]:=q;q:=l[q,v];v:=3-v;
             end;
           end;
          l[j,1]:=i;q:=j;v:=2;
          while q<>k do
           begin
            l[l[q,v],v]:=q;q:=l[q,v];v:=3-v;
           end;
         end;
  until not more;
  kuo_tree:=false;
 end;

procedure main;
 var i,j,k,tot:integer;
     b:boolean;
 begin
  fillchar(p,sizeof(p),0);tot:=0;
  repeat i:=0;
   repeat inc(i);
    if p[i]=0 then
     begin
      fillchar(l,sizeof(l),0);
      l[i,2]:=maxint;
      b:=kuo_tree;
      for j:=1 to n do
       for k:=1 to n do
        g[j,k]:=abs(g[j,k]);
     end
    else b:=false;
   until (i>n) or (b);
   if i<=n then inc(tot);
  until (i>n) or (tot=n div 2);
  writeln(tot);
  for i:=1 to n do
   if p[i]>0 then
    begin writeln(i,' ',p[i]);p[p[i]]:=0;end;
 end;

begin
 init;
 main;
end.
