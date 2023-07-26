const maxN = 1000;


var a: array[1..maxN,1..maxN] of longint;
    sum: array[0..maxN,0..maxN] of int64;
    m,n,k: word;
    s_max: int64;

procedure nhap;
var i,j: word;
begin
  readln(m,n,k);
  for i:=1 to m do
    for j:=1 to n do read(a[i,j]);

end;

procedure xuli;
var i,j,u,v: word;  s: int64;
begin
  s_max := -maxlongint;
  fillchar(sum,sizeof(sum),0);

  for i:=1 to m do
    for j:=1 to n do sum[i,j] := a[i,j] + sum[i-1,j] + sum[i,j-1] - sum[i-1,j-1];

  for i:=1 to m-k+1 do
    for j:=1 to n-k+1 do
      begin
         u := i+k-1; v:= j+k-1;
         s := sum[u,v] - sum[i-1,v] - sum[u,j-1] + sum[i-1,j-1];
         if s > s_max then s_max := s;
      end;

  write(s_max);
end;

begin
 assign(input,'caycanh.inp'); reset(input);
 assign(output,'caycanh.out'); rewrite(output);
    nhap;
    xuli;
 close(input); close(output);
end.
