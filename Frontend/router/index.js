import Vue from 'vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'

Vue.use(VueRouter)


const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/login',
    name: 'Login',
    // route level code-splitting
    // this generates a separate chunk (about.[hash].js) for this route
    // which is lazy-loaded when the route is visited.
    component: () => import(/* webpackChunkName: "about" */ '../views/Login.vue')
  },
  {
    path: '/teacherPage',
    name: 'teacherPage',
    component: () => import(/* webpackChunkName: "about" */ '../views/teacherPage.vue')
  },
  {
    path: '/:classID',
    name: 'Home',
    props: true,
    component: () => import(/* webpackChunkName: "about" */ '../views/attendancePage.vue')
  },
  // {
  //   path: '/teacherPage/$name',
  //   name: 'teacherPage',
  //   component: () => import(/* webpackChunkName: "about" */ '../views/teacherPage.vue')
  // }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
