uses math;
const   fi='nopot.inp';
        fo='nopot.out';
        maxn=100000;
        maxm=1000000;
var     test,it: longint;
        pa,r:array[1..maxn] of longint;
        d,c,w,ww:array[1..maxM] of longint;
        n,m,q,s,k: longint;

function getroot(u:longint):longint;
begin
        while pa[u]<>u do u:=pa[u];
        exit(u);
end;

procedure union(u,v: longint);
begin
        u:=getroot(u);
        v:=getroot(v);
        if u=v then exit;
        if r[u]>r[v] then pa[v]:=u else
        if r[u]<r[v] then pa[u]:=v else
        begin
                inc(r[u]);
                pa[v]:=u;
        end;
end;

procedure process;
var iq,i,tp,cp,v1,v2:longint;
begin
        readln(n,m,q);
        for i:=1 to m do readln(d[i],c[i],w[i]);
        for iq:=1 to Q do
        begin
                for i:=1 to n do pa[i]:=i;
                ww:=w;
                read(k,s);
                for i:=1 to s do
                begin
                        read(tp,cp);
                        ww[tp]:=cp;
                end;
                for i:=1 to m do
                if ww[i] < ww[k] then union(d[i],c[i]);
                v1:=getroot(d[k]);
                v2:=getroot(c[k]);
            	if v1=v2 then writeln('YES') else writeln('NO');
        end;
end;

begin
        assign(input,fi);reset(input); assign(output,fo);rewrite(output);
        readln(test);
        for iT:=1 to Test do process;
        close(input); close(output);
end.
