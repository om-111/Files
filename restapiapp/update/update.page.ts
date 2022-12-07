import { Component, OnInit } from '@angular/core';

import { Router, ActivatedRoute } from "@angular/router";
import { FormGroup, FormBuilder } from "@angular/forms";
import { UserCrudService } from './../services/user-crud.service';


@Component({
  selector: 'app-update',
  templateUrl: './update.page.html',
  styleUrls: ['./update.page.scss'],
})

export class UpdatePage implements OnInit {

  updateUserFg: FormGroup=this.formBuilder.group(
    {name: [''],
    email: [''],
    username: ['']}
  );
  id: any;

  constructor(
    private userCrudService: UserCrudService,
    private activatedRoute: ActivatedRoute,
    public formBuilder: FormBuilder,
    private router: Router
  ) {
    this.id = this.activatedRoute.snapshot.paramMap.get('id');
  }

  ngOnInit() {
    this.fetchUser(this.id);
    this.updateUserFg = this.formBuilder.group({
      name: [''],
      email: [''],
      username: ['']
    })
  }

  fetchUser(id:Number) {
    this.userCrudService.getUser(id).subscribe((data) => {
      this.updateUserFg.setValue({
        name: data[0],
        email: data[1],
        username: data[2]
      });
    });
  }

  onSubmit() {
    if (!this.updateUserFg.valid) {
      return false;
    } else {
      this.userCrudService.updateUser(this.id, this.updateUserFg.value)
        .subscribe(() => {
          this.updateUserFg.reset();
          this.router.navigate(['/list']);
        })
      return true;
    }
  }

}