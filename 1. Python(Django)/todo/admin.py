from django.contrib import admin
from .models import Post

# Registering Post Model on the admin Panel
admin.site.register(Post)