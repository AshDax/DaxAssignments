from django.urls import path
from . import views

urlpatterns = [

    # Path for listing todos
    path('', views.todo_list, name='todo_list'),

    # Path for creating new todos 
    path('create',views.create, name= "create"),

    # Path for updating todos
    path('edit/<int:id>',views.edit,name="edit"),
    path('update/<int:id>',views.update,name="update"),

    # Path for deleting todos
    path('delete/<int:id>', views.delete,name="delete"),
    
] 