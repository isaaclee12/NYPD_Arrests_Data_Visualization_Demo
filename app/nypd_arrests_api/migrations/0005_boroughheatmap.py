# Generated by Django 4.1.2 on 2022-10-29 00:15

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('nypd_arrests_api', '0004_rename_arrest_precint_arrests_arrest_precinct'),
    ]

    operations = [
        migrations.CreateModel(
            name='BoroughHeatMap',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
            ],
        ),
    ]
