file=open('cordinates.txt');
print 'glBegin(GL_POLYGON);'
print 'glColor3f(1,1,1)'
for line in file:
    x=line.split(',');
    print 'glVertex2f('+line[:].strip()+');'

print 'glEnd();'
