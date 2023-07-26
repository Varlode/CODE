uses math;
const
        fi='dentruong.inp';
        fo='dentruong.out';
        maxn=1000;
        oo=2000000000;
type
        long=longint;
var
        a:array[1..maxn,1..maxn] of long;
        d,s:array[1..maxn]of qword;
        f:array[1..maxn]of boolean;
        n,m:long;

procedure docfile;
var i,u,v,L,k,j:long;
begin
        readln(n,m);
        for i:=1 to n do for j:=1 to n do a[i,j]:=oo;
        for i:=1 to m do
                begin
                        readln(k,u,v,L);
                        a[u,v]:=L;
                        if k=2 then a[v,u]:=L;
                end;
end;

procedure xuli;
var i,u,v:long;   min:long;
begin
        for i:=1 to n do d[i]:=oo;
        fillchar(f,sizeof(f),true);
        fillchar(s,sizeof(s),0);
        d[1]:=0;
        s[1]:=1;
        f[1] := false;
        for i:=2 to n do
           if (a[1,i]<>oo) then
             begin
               d[i] := a[1,i]; s[i] := 1;
             end;

        repeat
                min:=oo;
                u:=0;
                for i:=1 to n do if f[i] and (d[i]<min) then
                        begin
                                min:=d[i];
                                u:=i;
                        end;
                if (u=0) or (u=n) then break;
                f[u]:=false;

                for v:=1 to n do
                  if f[v] and (d[v]>d[u]+a[u,v]) then
                        begin
                                d[v]:=d[u]+a[u,v];
                                s[v]:=s[u];
                        end
                  else
                  if f[v] and (d[v]=d[u]+a[u,v]) then s[v]:=s[v]+s[u];
        until false;
        writeln(d[n],#32,s[n]);
end;

begin
        assign(input,fi); reset(input); assign(output,fo); rewrite(output);
        docfile;
        xuli;
        close(input);  close(output);
end.

