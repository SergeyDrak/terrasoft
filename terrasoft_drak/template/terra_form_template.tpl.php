<div class="wrapper-terra">
    <div class="wrapper-form">
        <h3 class="promo">
          <?php print render($form['promo']); ?>
        </h3>
        <div class="domain">
            <div class="domain-left inline-item">
              <?php print render($form['domain']); ?>
            </div>
            <div class="domain-right inline-item">
              <?php print render($form['domain_suffix']); ?>
            </div>
        </div>
        <div class="login">
          <?php print render($form['login']); ?>
        </div>
        <div class="country">
          <?php print render($form['country']); ?>
        </div>
        <div class="city">
          <?php print render($form['city']); ?>
        </div>
        <div class="phone">
            <div class="phone-left inline-item">
              <?php print render($form['code']); ?>
            </div>
            <div class="phone-right inline-item">
              <?php print render($form['phone']); ?>
            </div>
        </div>
      <?php print drupal_render_children($form); ?>
        <div class="bottom-form"><a href="#">Create Accounts</a></div>
    </div>
</div>