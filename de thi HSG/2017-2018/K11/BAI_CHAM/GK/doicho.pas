uses math;
const maxN = 1000;

var a: array[1..MaxN,1..maxN] of longint;
    m,n,u,v: longint;

//-------------------------------
procedure swap(var a,b:longint);
var tam:longint;
begin
  tam :=a; a:=b; b:=tam;
end;

procedure xuli;
var i,j: longint;
begin
  for j:=1 to n do swap(a[u,j],a[v,j]);
  for i:=1 to m do
    begin
      for j:=1 to n do write(a[i,j],#32);
      writeln;
    end;
end;
//----------------------------
procedure nhap;
var i,j: longint;
begin
  readln(m,n,u,v);
  for i:=1 to m do
     for j:=1 to n do read(a[i,j]);
        
end;
//------------------------------
BEGIN
  assign(input,'doicho.inp'); reset(input);  assign(output,'doicho.out'); rewrite(output);
    nhap;
    xuli;
  close(input); close(output);
END.
