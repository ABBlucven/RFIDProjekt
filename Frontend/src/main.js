import Vue from 'vue'
import App from './App.vue'
import router from '../src/router'
import { rtdbPlugin } from 'vuefire'
Vue.use(rtdbPlugin)

Vue.config.productionTip = false

new Vue({
  router,
  render: h => h(App)
}).$mount('#app')
