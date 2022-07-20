from django.shortcuts import render, redirect
from django.utils import timezone
from .models import Post
from .forms import PostForm

# To view all the todos
def todo_list(request):
    todos = Post.objects.all()
    return render(request, 'todo/todo_list.html', {'todos': todos})

# To create a new todo
def create(request):
    if request.method=="POST":
        name=request.POST['title']
        des=request.POST['description']
        obj=Post.objects.create(title = name, description = des)
        obj.save()
        todos = Post.objects.all()
    return render(request, 'todo/todo_list.html', {'todos': todos})

# To push details to be edited to Edit.html
def edit(request,id):
    object=Post.objects.get(id=id)
    return render(request,'todo/edit.html',{'object':object})

# To update the todos
def update(request,id):
    object=Post.objects.get(id=id)
    form=PostForm(request.POST,instance=object)
    if form.is_valid:
        form.save()
    return redirect(todo_list)

# To delete a todo
def delete(request,id):   
    todos = Post.objects.filter(id=id).delete()
    return redirect(todo_list)
