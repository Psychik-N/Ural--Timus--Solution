var n,m,x,left1,s,m1,back,sp:longint;
    a,b,pb,c,d,pc,g,sf,ta,tb:array [0..150] of longint;
    fl,fm:array [0..11,0..150] of longint;
    cr:array [0..20000] of longint;
procedure rnd;
var i,j,t:longint;
begin
    for i:=1 to m do
      tb[i]:=random(10000);
    for i:=1 to m do
      for j:=1 to m do
        if tb[i]<tb[j] then begin
          t:=b[i];
          b[i]:=b[j];
          b[j]:=t;
          t:=tb[i];
          tb[i]:=tb[j];
          tb[j]:=t;
          t:=pb[i];
          pb[i]:=pb[j];
          pb[j]:=t;
        end;
end;
procedure go;
var i,j,f1,f2,e,t:longint;
begin
    if sp=10000 then exit;
halt;
    inc(sp);
    if x=m1 then begin
      e:=1;
      for i:=1 to n do
        inc(d[c[i]]);
      for i:=1 to n do
        for j:=1 to n do
          if c[i]<c[j] then begin
            t:=c[i];
            c[i]:=c[j];
            c[j]:=t;
            t:=pc[i];
            pc[i]:=pc[j];
            pc[j]:=t;
          end;
      for i:=1 to m do begin
        writeln(d[i]);
        for j:=1 to d[i] do begin
          write(pc[e]);
          inc(e);
          write(' ');
        end;
        writeln;
      end;
      halt;
    end;
    f1:=fl[x][0];
    for i:=s to n do begin
      if (c[i]<>0) or (left1<a[i]) or (fm[x][a[i]]<>0) then continue;
      f2:=fl[x][0];
      c[i]:=pb[x];
      pc[i]:=a[i];
      back:=s;
      if left1=a[i] then begin
        inc(x);
        left1:=b[x];
        s:=sf[pb[x]];
        if cr[left1]<>0 then begin
          fillchar(fm[x],600,0);
          go;
        end;
        dec(x);
        left1:=a[i];
      end
      else begin
        for j:=1 to f2 do
          if (fl[x][j]>a[i]) or (fm[x][fl[x][j]-a[i]]=0) then begin
            fm[x][fl[x][j]-a[i]]:=1;
            inc(fl[x][0]);
            fl[x][fl[x][0]]:=fl[x][j]-a[i];
          end;
        left1:=left1-a[i];
        s:=i+1;
        if cr[left1]=1 then go;
        left1:=left1+a[i];
        for j:=f2+1 to fl[x][0] do
          fm[x][fl[x][j]]:=0;
        fl[x][0]:=f2;
        if fm[x][a[i]]=0 then begin
          fm[x][a[i]]:=1;
          inc(fl[x][0]);
          fl[x][fl[x][0]]:=a[i];
        end;
      end;
      s:=back;
      c[i]:=0;
    end;
    for i:=f1+1 to fl[x][0] do
      fm[x][fl[x][i]]:=0;
    fl[x][0]:=f1;
end;
procedure nxt;
var i:longint;
begin
    sp:=0;
    rnd;
    for i:=0 to 150 do begin
      d[i]:=0;
      c[i]:=0;
    end;
    s:=1;
    x:=1;
    left1:=b[1];
    go;
end;
procedure main;
var i,j,t:longint;
begin
    randomize;
    read(n,m);
    sp:=0;
    m1:=m+1;
    for i:=1 to n do read(a[i]);
    for i:=1 to m do begin
      read(b[i]);
      pb[i]:=i;
    end;
    for i:=1 to n do
      for j:=10000 downto 0 do
        if cr[j]=1 then
          cr[j+a[i]]:=1;
    for i:=1 to n do
      for j:=1 to n do
        if a[i]>a[j] then begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
    for i:=1 to m do
      for j:=1 to n do
        if a[j]<=b[i] then begin
          sf[i]:=j;
          break;
        end;
    while true do nxt;
end;
begin
main;
end.
