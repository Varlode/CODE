// ma bai BYTESE1

uses math;
const maxM = 100; MaxN = 100;
      Vx : array[1..4] of -1..1 =(-1,0,1,0);
      Vy : array[1..4] of -1..1 =(0,1,0,-1);

var C: array[1..maxM,1..maxN] of longint;
    F: array[1..maxN,1..maxN] of int64;
    free: array[1..maxM,1..maxN] of boolean;
    K,M,N,a,b,T: longint;

//-------------------------------------------
procedure Dijkstra;
var i,j,ux,uy,min,p,u,v: longint;
 begin
   fillchar(free,sizeof(free),true);
   for i:=1 to M do
    for j:=1 to N do F[i,j] := maxlongint;

   F[1,1] := C[1,1];
   free[1,1] := false;
   F[1,2] := F[1,1] + C[1,2];
   F[2,1] := F[1,1] + C[2,1];

   repeat
    ux := 0; uy:=0; min := maxlongint;
    for i := 1 to M do
     for j := 1 to N do
       if Free[i,j] and (F[i,j] < min) then
            begin  min := F[i,j];  ux := i; uy := j; end;

    if ((ux=a) and (uy=b)) or ((ux = 0) and (uy=0)) then Break;
    Free[ux,uy] := False;

    for p:=1 to 4 do
      begin
        u := ux + Vx[p];
        v := uy + Vy[p];
        if (u>=1) and (u<=M) and (v>=1) and (v<=N) then
         begin
            if free[u,v] and (F[ux,uy]+C[u,v] < F[u,v]) then F[u,v] := F[ux,uy] + C[u,v];
         end;

      end;
   until False;

 end;
//---------------------------------------------------------
procedure nhap;
var i,u,v: longint;
begin
   Readln(K);
   for i:=1 to K do
    begin
      readln(M,N);
      for u:=1 to M do
       for v:= 1 to N do read(C[u,v]);
      readln;
      readln(a,b,T);
      Dijkstra;
      if (F[a,b]>T) then writeln('NO')
      else begin writeln('YES'); writeln(T-F[a,b]); end;

    end;
end;
//---------------------------------------------------------

BEGIN
 assign(input,'giaicuu.inp'); reset(input);  assign(output,'giaicuu.out'); rewrite(output);
    nhap;
 close(input);  close(output);

END.
